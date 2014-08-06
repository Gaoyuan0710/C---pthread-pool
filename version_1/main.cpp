// =====================================================================================
// 
//       Filename:  main.cpp
//
//    Description:  
//
//        Version:  1.0
//        Created:  2014年05月03日 00时37分14秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Gaoyuan, sishuiliunian0710@gmail.com
//        Company:  Class 1204 of Computer Science and Technology
// 
// =====================================================================================

#include <iostream>
#include <unistd.h>
#include "myPthreadPool.h"
#include "myWork.h"
#include "myWork.cpp"
#include "myPthreadPool.cpp"
#include "myPthread.h"
#include "myPthread.cpp"

using namespace gaoyuan;









int main(int argc, char *argv[])
{
	int max_pthread_num = 3;
	int work_num = 10;
	
	MyPthreadPool test_pool(max_pthread_num);
	test_pool.my_pthread_pool_init();


	//sleep (5);

	for(int i = 0; i < work_num; i++ ){
		test_pool.my_pthread_pool_add_work(work, &i);
	}
	
	sleep(5);
	cout << "SSS" << endl;
	test_pool.destory_pthread_pool();


	return 0;
}

