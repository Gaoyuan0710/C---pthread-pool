// =====================================================================================
// 
//       Filename:  myCond.cpp
//
//    Description:  
//
//        Version:  1.0
//        Created:  2014年05月01日 20时56分28秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Gaoyuan, sishuiliunian0710@gmail.com
//        Company:  Class 1204 of Computer Science and Technology
// 
// =====================================================================================

#include "myCond.h"
namespace gaoyuan{
int MyCond::cond_init(pthread_cond_t *cond) {
	int status;

	status = pthread_cond_init(cond, NULL);

	if (status != 0) {
		cout << "the cond init wrong " << endl;
		return -1;
	}
	return 0;
}
int MyCond::cond_destroy(pthread_cond_t *cond){
	int status;

	status = pthread_cond_destroy(cond);

	if (status != 0) {
		cout << "cond destroy wrong " << endl;
		return -1;
	}
	return 0;
}
}
