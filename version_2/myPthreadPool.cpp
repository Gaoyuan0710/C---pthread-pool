// =====================================================================================
// 
//       Filename:  myPthreadPool.cpp
//
//    Description:  
//
//        Version:  1.0
//        Created:  2014年05月02日 22时51分28秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Gaoyuan, sishuiliunian0710@gmail.com
//        Company:  Class 1204 of Computer Science and Technology
// 
// =====================================================================================

#include "myPthreadPool.h"
#include "myPthread.h"
#include "myCond.h"
#include "myMutex.h"
#include <queue>
#include "myCond.cpp"
#include "myMutex.cpp"

using std::cout;
using std::endl;
using std::queue;

namespace gaoyuan{
int MyPthreadPool::current_queue_size = 0;
pthread_mutex_t MyPthreadPool::mutex;
pthread_cond_t MyPthreadPool::cond;
bool MyPthreadPool::destory_flag = false;
int MyPthreadPool::max_thread_num = 0;
queue <MyWork *>MyPthreadPool::task_queue;
queue <pthread_t *>MyPthreadPool::pthread_queue;

void MyPthreadPool::my_pthread_pool_init(){
	MyMutex::mutex_init(&mutex);
	MyCond::cond_init(&cond);
	pthread = new pthread_t[this->max_thread_num];

	for (int i = 0 ; i < this->max_thread_num; i++) {
		MyPthread::my_pthread_create(&pthread[i], my_thread_pool_routine);
		pthread_queue.push(&pthread[i]);
	}
}

void *MyPthreadPool::my_thread_pool_routine(void *argv) {
	cout << "pthread " << MyPthread::my_pthread_self_id()  << "is starting" << endl;

	while (1){
		MyMutex::mutex_lock(&mutex);
		while ((0 == current_queue_size) && (destory_flag == false)) {
			cout << "the queue of task is null, thread " << MyPthread::my_pthread_self_id() << " is waitting " << endl;
			MyCond::cond_wait(&cond, &mutex);
		} 
		if (true == destory_flag ) {
			MyMutex::mutex_unlock(&mutex);
			cout << "phtread  " << MyPthread::my_pthread_self_id() << " will get over " << endl;
			MyPthread::my_pthread_exit(NULL);
		}
		cout << "pthread " << MyPthread::my_pthread_self_id() << " begin to  work now " << endl;

		current_queue_size--;
		
		MyWork *tmp_work;
		tmp_work = (task_queue.front());
		task_queue.pop();
		MyMutex::mutex_unlock(&mutex);
		(tmp_work->work)((int *)tmp_work->arg);
		}
}
void MyPthreadPool::my_pthread_pool_add_work(void *(*work)(void *), void *arg) {
	MyMutex::mutex_lock(&mutex);
	task_queue.push(&test[*(int *) arg]);
	current_queue_size++;
	MyMutex::mutex_unlock(&mutex);
	MyCond::cond_signal(&cond);
}
void MyPthreadPool::destory_pthread_pool() {
	destory_flag = true;
	MyCond::cond_broadcast(&cond);

	for (int i = 0; i < max_thread_num; i++ ) {
		pthread_t *pthread_tmp;
		pthread_tmp = pthread_queue.front();
		pthread_join((*pthread_tmp), NULL);
		pthread_queue.pop();
	}
	while (task_queue.empty() != true) {
		task_queue.pop();
	}
	MyCond::cond_destroy(&cond);
	MyMutex::mutex_destory(&mutex);
}
}

