// =====================================================================================
// 
//       Filename:  myMutex.cpp
//
//    Description:  
//
//        Version:  1.0
//        Created:  2014年05月01日 20时14分53秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Gaoyuan, sishuiliunian0710@gmail.com
//        Company:  Class 1204 of Computer Science and Technology
// 
// =====================================================================================

#include "myMutex.h"

namespace gaoyuan{
int MyMutex::mutex_init(pthread_mutex_t *mutex) {
	int status;
	
	status = pthread_mutex_init(mutex, NULL);

	if (status != 0) {
		cout<< "The mutex init wrong " << endl;
		return -1;
	}
	
	return 0;
}
int MyMutex::mutex_destory(pthread_mutex_t *mutex){
	int status;

	status = pthread_mutex_destroy(mutex);

	if (status != 0) {
		cout << "The mutex destory wrong " << endl;
		return -1;
	}

	return 0;
}
}
