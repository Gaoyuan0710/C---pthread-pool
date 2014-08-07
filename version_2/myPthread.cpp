// =====================================================================================
// 
//       Filename:  myPhtread.cpp
//
//    Description:  
//
//        Version:  1.0
//        Created:  2014年05月02日 12时30分31秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Gaoyuan, sishuiliunian0710@gmail.com
//        Company:  Class 1204 of Computer Science and Technology
// 
// =====================================================================================

#include "myPthread.h"

namespace gaoyuan{
bool MyPthread::my_pthread_equal(pthread_t thread1, pthread_t thread2) {
	int status;

	status = pthread_equal(thread1, thread2);

	if (0 == status) {
		return false;
	}
	return true;
}
int MyPthread::my_pthread__once(pthread_once_t *oncetrol, void(*init_routine)(void)) {
	return pthread_once(oncetrol, init_routine);
}
void MyPthread::my_pthread_exit(void * retval) {
	pthread_exit(retval);
}
}
