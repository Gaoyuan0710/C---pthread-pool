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

int i[30] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
MyWork test_work[30] = {MyWork(work, (void *)&i[0]),  MyWork(work, (void *)&i[1]), MyWork(work, (void *)&i[2]), MyWork(work, (void *)&i[3]), MyWork(work, (void *)&i[4]), MyWork(work, (void *)&i[5]), MyWork(work, (void *)&i[6]), MyWork(work, (void *)&i[7]), MyWork(work, (void *)&i[8]), MyWork(work, (void *)&i[9]), MyWork(work, (void *)&i[10]),  MyWork(work, (void *)&i[11]), MyWork(work, (void *)&i[12]), MyWork(work, (void *)&i[13]), MyWork(work, (void *)&i[14]), MyWork(work, (void *)&i[15]), MyWork(work, (void *)&i[16]), MyWork(work, (void *)&i[17]), MyWork(work, (void *)&i[18]), MyWork(work, (void *)&i[19]),MyWork(work, (void *)&i[20]),  MyWork(work, (void *)&i[21]), MyWork(work, (void *)&i[22]), MyWork(work, (void *)&i[23]), MyWork(work, (void *)&i[24]), MyWork(work, (void *)&i[25]), MyWork(work, (void *)&i[26]), MyWork(work, (void *)&i[27]), MyWork(work, (void *)&i[28]), MyWork(work, (void *)&i[29])   };

	class MyPthreadPool{
		public:
			MyPthreadPool(int max_pthread_num = 0){
				this->max_pthread_num = max_pthread_num;
			}
			void my_pthread_pool_init();
			static void * my_pthread_pool_routine(void *arg);
			static void * my_pthread_manager(void *arg);
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
	};
}

#endif

