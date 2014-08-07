// =====================================================================================
// 
//       Filename:  myMutex.h
//
//    Description:  
//
//        Version:  1.0
//        Created:  2014年05月01日 18时45分57秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Gaoyuan, sishuiliunian0710@gmail.com
//        Company:  Class 1204 of Computer Science and Technology
// 
// =====================================================================================

#ifndef _MYMUTEX_H
#define _MYMUTEX_H

#include <iostream>
#include <unistd.h>
#include <pthread.h>

namespace gaoyuan{
using std::cout;
using std::endl;

class MyMutex {
	public:
		MyMutex() {}
		static int mutex_init(pthread_mutex_t *mutex);
		static int mutex_destory(pthread_mutex_t *mutex);
		static int mutex_try_lock(pthread_mutex_t *mutex) {
			int status;

			status = pthread_mutex_trylock(mutex);

			if (status != 0) {
				cout << "There is a lock already" << endl;
				return -1;
			}
			return 0;
		}
		static int mutex_lock(pthread_mutex_t *mutex){
			int status;

			status = pthread_mutex_lock(mutex);
			if (status != 0) {
				cout << "The process that try to lock is wrong" << endl;
				return -1;
			}
			return 0;
		}
		static int mutex_unlock(pthread_mutex_t *mutex){
			int status;

			status = pthread_mutex_unlock(mutex);
			if (status != 0) {
				cout << "The process that try to unlock wrong " << endl;
				return -1;
			}
			return 0;
		}
};
}
#endif
