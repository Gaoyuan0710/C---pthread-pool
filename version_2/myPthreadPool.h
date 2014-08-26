/*
 * =====================================================================================
 *
 *       Filename:  myPthreadPool.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月07日 09时59分11秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Gaoyuan, sishuiliunian0710@gmail.com
 *        Company:  Class 1204 of Computer Science and Technology
 *
 * =====================================================================================
 */
#ifndef _MY_PTHREADPOOL_H
#define _MY_PTHREADPOOL_H

#include <iostream>
#include <queue>
#include <vector>
#include <pthread.h>
#include "myWork.h"

using std::queue;

namespace gaoyuan{
	class MyPthread my_pthread;

int i[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
MyWork test_work[10] = {MyWork(work, (void *)&i[0]),  MyWork(work, (void *)&i[1]), MyWork(work, (void *)&i[2]), MyWork(work, (void *)&i[3]), MyWork(work, (void *)&i[4]), MyWork(work, (void *)&i[5]), MyWork(work, (void *)&i[6]), MyWork(work, (void *)&i[7]), MyWork(work, (void *)&i[8]), MyWork(work, (void *)&i[9]) };

	class MyPthreadPool{
		public:
			MyPthreadPool(int max_pthread_num = 0){
				this->max_pthread_num = max_pthread_num;
			}
			void my_pthread_pool_init();
			static int my_pthread_pool_routine(void *arg);
			static void my_pthread_manager(void *arg);
			static bool if_pthread_alive(pthread_t pid);
			void my_pthread_pool_add_work(void *(* work)(void *arg), void * arg);
			void my_pthread_pool_destory();
		private:
			static pthread_t manage_pthread;
			static pthread_cond_t cond;
			static pthread_mutex_t mutex;
			static pthread_mutex_t pthread_queue_mutex;
			static queue<MyWork *> my_work_queue;
			static queue<pthread_t *> pthread_work_queue;
			static queue<pthread_t *> pthread_relax_queue;
			static int max_pthread_num;
			static int current_pthread_num;
			static int exit_pthread_num;
			static int current_work_size;
			static bool destory_flag;
	}
}

#endif

