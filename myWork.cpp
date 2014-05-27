// =====================================================================================
// 
//       Filename:  myWork.cpp
//
//    Description:  
//
//        Version:  1.0
//        Created:  2014年05月02日 21时41分00秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Gaoyuan, sishuiliunian0710@gmail.com
//        Company:  Class 1204 of Computer Science and Technology
// 
// =====================================================================================
#include "myWork.h"
#include "myPthread.h"
using std::cout;
using std::endl;

namespace gaoyuan{
void *work(void *arg) {
	cout << "Thread id is " << MyPthread::my_pthread_self_id() << " while the id of the task is " << *(int *)arg << endl;
	sleep(2);
	cout << "the task whose id is " << *(int *)arg << " is over while the thread is " << MyPthread::my_pthread_self_id();

	return NULL;
}
}


