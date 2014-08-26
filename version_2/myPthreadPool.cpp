/*
 * =====================================================================================
 *
 *       Filename:  myPthreadPool.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月08日 11时25分03秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Gaoyuan, sishuiliunian0710@gmail.com
 *        Company:  Class 1204 of Computer Science and Technology
 *
 * =====================================================================================
 */

#include <iostream>
#include <queue>
#include <vector>
#include "myPthreadPool.h"
#include "myWork.h"
#include "myMutex.h"
#include "myCond.h"
#include "myPthread.h"

using std::cout;
using std::cin;
using std::endl;
using std::queue;
using std::vector;

namespace gaoyuan{



pthread_t MyPthreadPool::manage_pthread;
pthread_cond_t MyPthreadPool::cond;
pthread_mutex_t MyPthreadPool::mutex;
pthread_mutex_t MyPthreadPool::pthread_queue_mutex;
queue <MyWork *> MyPthreadPool::my_work_queue;
queue <pthread_t *> MyPthreadPool::pthread_work_queue;
queue <pthread_t *> MyPthreadPool::pthread_relax_queue;
int MyPthreadPool::max_pthread_num = 0;
int MyPthreadPool::current_pthread_num = 0;
int MyPthreadPool::exit_pthread_num = 0;
int MyPthreadPool::current_work_size = 0;
bool MyPthreadPool::destory_flag = false;

void MyPthreadPool::my_pthread_pool_init(){
	MyMutex::mutex_init(&mutex);
	MyMutex::mutex_init(&pthread_queue_mutex);
	MyCond::cond_init(&cond);

	MyPthread::my_pthread_create(&manage_pthread, my_pthread_manager);

	for (int i = 0; i < this->max_pthread_num; i++){
		pthread_t pthread_tmp;

		MyPthread::my_pthread_create(&pthread_tmp, my_pthread_pool_routine);
		pthread_work_queue.push(&pthread_tmp);
		current_pthread_num++;
	}
}
int MyPthreadPool::my_pthread_pool_routine(void *argv){
	cout << "Pthread " << MyPthread::my_pthread_self_id() << " is starting " << endl;

	while (true){
		MyMutex::mutex_lock(&mutex);

		while ((current_work_size == 0) && (destory_flag == false)){
			cout << "Pthread " << MyPthread::my_pthread_self_id() << " is sleep to wait for work" << endl;
			MyCond::cond_wait(&cond, &mutex);

			if (exit_pthread_num > 0){
				exit_pthread_num--;
				cout << "Pthread " << MyPthread::my_pthread_self_id() << " is exiting " << endl;
				MyMutex::mutex_unlock(&mutex);
				MyPthread::my_pthread_exit(NULL);
			}
		}
		if (destory_flag == true){
			MyMutex::mutex_unlock(&mutex);
			cout << "Pthread " << MyPthread::my_pthread_self_id << " is exiting " << endl;
			MyPthread::my_pthread_exit(NULL);
		}

		cout << "Pthread " << MyPthread::my_pthread_self_id() << " begin to work now " << endl;

		MyWork *tmp_work = (my_work_queue.front());
		my_work_queue.pop();
		MyMutex::mutex_unlock(&mutex);
		(tmp_work)((int *)tmp_work->arg);
	}
	MyPthread::my_pthread_exit(NULL);
	return 0;
}
int MyPthreadPool::my_pthread_pool_add_work(void *(*work)(void *), void *arg){
	MyMutex::mutex_lock(&mutex);
	my_work_queue.push(work);
	current_work_size++;
	MyCond::cond_signal(&cond);
	MyMutex::mutex_unlock(&mutex);

	return 0;
}
void MyPthreadPool::my_pthread_manager(void *arg){
	while (destory_flag == false){
		sleep(50);

		int work_size = current_work_size;
		int pthread_num = current_pthread_num;


		if (pthread_num < work_size / 3){
			MyMutex::mutex_lock(&mutex);

			cout << "There are too many works and too less pthreads, we should add some pthreads" << endl;
			
			for (int i = pthread_num; i < work_size / 3; i++){
				pthread_t pthread_tmp;

				MyPthread::my_pthread_create(&pthread_tmp, my_pthread_pool_routine);
				pthread_work_queue.push(&pthread_tmp);
				current_pthread_num++;
			}
		}
		if (pthread_num / 3 > work_size ){
			MyMutex::mutex_lock(&mutex);
			exit_pthread_num = pthread_num / 3 - work_size;
			MyMutex::mutex_unlock(&mutex);

			cout << "There are too mant pthreads and too less works, we should kill some pthreads" << endl;
			for (int i = 0; i < exit_pthread_num; i++){
				MyCond::cond_signal(&cond);
			}
		}
	}
}
void MyPthreadPool::my_pthread_pool_destory(){
	destory_flag = true;

	MyPthread::my_pthread_join(manage_pthread);
	cout << "Kill manage pthread " << endl;

	MyCond::cond_broadcast(&cond);
	for (int i = 0; i < current_pthread_num; i++){
		pthread_t pthread_tmp;

		pthread_tmp = pthread_work_queue.front();
		MyPthread::my_pthread_join(pthread_tmp);
		pthread_work_queue.pop();
	}
	cout << "Kill work pthread " << endl;

	MyCond::cond_destroy(&cond);
	MyMutex::mutex_destory(&mutex);

	cout << "Destory cond and mutex " << endl;
	cout << "Deal work finished " << endl;
}
}

