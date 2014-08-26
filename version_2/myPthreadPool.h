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
#include "myWord.h"

using std::queue;

namespace gaoyuan{
	class MyPthread my_pthread;

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

