// =====================================================================================
// 
//       Filename:  myPthreadTest.cpp
//
//    Description:  
//
//        Version:  1.0
//        Created:  2014年05月02日 12时59分27秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Gaoyuan, sishuiliunian0710@gmail.com
//        Company:  Class 1204 of Computer Science and Technology
// 
// =====================================================================================

#include "../myPthread.h"
#include "../myPthread.cpp"

using namespace gaoyuan;
using std::cout;
using std::endl;

void *assisthread(void *arg) {
	cout << "I am helping to do some jobs" << endl;
	sleep(3);
	MyPthread::my_pthread_exit(0);
}

int main(int argc, char *argv[])
{
	pthread_t thread;
	int status;

	MyPthread::my_pthread_create(&thread, assisthread);
	MyPthread::my_pthread_join(thread, NULL);
	cout << "thread's exit is caused by " << status << endl;



	return 0;
}

