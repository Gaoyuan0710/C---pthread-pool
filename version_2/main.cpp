// =====================================================================================
// 
//       Filename:  main.cpp
//
//    Description:  
//
//        Version:  1.0
//        Created:  2014年08月26日 17时48分13秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Gaoyuan, sishuiliunian0710@gmail.com
//        Company:  Class 1204 of Computer Science and Technology
// 
// =====================================================================================

#include <iostream>

#include "myCond.h"
#include "myMutex.h"
#include "myPthread.h"
#include "myPthreadPool.h"
#include "myWork.h"

using namespace gaoyuan;

using std::cout;
using std::cin;
using std::endl;

int main(int argc, char *argv[])
{
	int max_pthread_num = 3;
	int work_num = 2;

	MyPthreadPool my_pthread_pool_test(max_pthread_num);
	my_pthread_pool_test.my_pthread_pool_init();

	for (int i = 0; i < work_num; i++){
		my_pthread_pool_test.my_pthread_pool_add_work(work, &i);
	}

	while(1);


	return 0;
}

