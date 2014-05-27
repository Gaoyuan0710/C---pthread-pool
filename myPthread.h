// =====================================================================================
// 
//       Filename:  myPhtread.h
//
//    Description:  
//
//        Version:  1.0
//        Created:  2014年05月02日 11时52分57秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Gaoyuan, sishuiliunian0710@gmail.com
//        Company:  Class 1204 of Computer Science and Technology
// 
// =====================================================================================

#ifndef _MYPTHREAD_H
#define _MYPTHREAD_H

#include <iostream>
#include <unistd.h>
#include <pthread.h>

namespace gaoyuan{
using std::cout;
using std::endl;

class MyPthread {
	public:
		MyPthread(){}
		static int my_pthread_create(pthread_t *thread, void * (*start_routine)(void *) ) {
			int status;

			status = pthread_create(thread, NULL, start_routine, NULL);

			if (status != 0) {
				cout << "Pthread create wrong " << endl;
				return -1;
			}
			return 0;
		}
		static pthread_t my_pthread_self_id () {
			return pthread_self();
		}
		static bool my_pthread_equal(pthread_t thread1, pthread_t thread2);
		static int my_pthread__once(pthread_once_t *once_control, void(*init_routine)(void));
		static void my_pthread_exit(void *retval);
		static int my_pthread_join(pthread_t thread, void ** thread_return) {
			return pthread_join(thread, thread_return);
		}
		static int my_pthread_join(pthread_t thread) {
			return pthread_join(thread, NULL);
		}
};
}
#endif
