// =====================================================================================
// 
//       Filename:  myPthreadPool.h
//
//    Description:  
//
//        Version:  1.0
//        Created:  2014年05月02日 20时43分18秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Gaoyuan, sishuiliunian0710@gmail.com
//        Company:  Class 1204 of Computer Science and Technology
// 
// =====================================================================================

#ifndef _MYPTHREADPOOL_H
#define _MYPTHREADPOOL_H

#include <iostream>
#include <pthread.h>
#include <queue>
#include "myWork.h"

using std::queue;

namespace gaoyuan{
  
 int i [10] = {1,2,3,4,5,6,7,8,9,10};
MyWork test[10] = {MyWork(work, (void *)&i[0]), MyWork(work, (void *)&i[2]), MyWork(work, (void *)&i[3]), MyWork(work, (void *)&i[4]), MyWork(work, (void *)&i[5]), MyWork(work, (void *)&i[6]), MyWork(work, (void *)&i[7]), MyWork(work, (void *)&i[8]), MyWork(work, (void *)&i[9]), MyWork(work, (void *) &i[2]) };


  class MyPthreadPool {
	public:
		MyPthreadPool(int max_thread_num){this->max_thread_num = max_thread_num;}
		void my_pthread_pool_init();
		static void *my_thread_pool_routine(void *arg);
		void my_pthread_pool_add_work(void* (*work)(void *arg), void * arg);
		void destory_pthread_pool();
	private:
		    pthread_t *pthread;
static		pthread_cond_t cond;
static		pthread_mutex_t mutex;
static		queue <MyWork *> task_queue;
static		queue <pthread_t *> pthread_queue;
static      int max_thread_num;
static      int current_queue_size;
static		bool destory_flag;
};

}
#endif



