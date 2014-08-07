// =====================================================================================
// 
//       Filename:  myCond.h
//
//    Description:  
//
//        Version:  1.0
//        Created:  2014年05月01日 20时51分31秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Gaoyuan, sishuiliunian0710@gmail.com
//        Company:  Class 1204 of Computer Science and Technology
// 
// =====================================================================================

#ifndef _MYCOND_H
#define _MYCOND_H

#include <iostream>
#include <unistd.h>
#include <pthread.h>

using std::cout;
using std::endl;

namespace gaoyuan{
class MyCond {
	public:
	MyCond(){}
	static int cond_init (pthread_cond_t *cond);
	static int cond_destroy(pthread_cond_t *cond);
	static int cond_wait(pthread_cond_t *cond, pthread_mutex_t *mutex) {
		int status;

		status = pthread_cond_wait(cond, mutex);

		if (status != 0) {
			cout << "the process wait wrong " << endl;
			return -1;
		}
		return 0;
	}
	static int cond_signal(pthread_cond_t *cond) {
		int status;

		status = pthread_cond_signal(cond);

		if (status != 0) {
			cout << "send signal wrong " << endl;
			return -1;
		}
		return 0;
	}
	static int cond_broadcast(pthread_cond_t *cond) {
		int status;

		status = pthread_cond_broadcast(cond);

		if(status != 0 ) {
			cout << "send all signal wrong " << endl;
			return -1;
		}

		return 0;
	}

};
}
#endif
