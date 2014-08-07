// =====================================================================================
// 
//       Filename:  myMutexTest.cpp
//
//    Description:  
//
//        Version:  1.0
//        Created:  2014年05月01日 19时47分34秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Gaoyuan, sishuiliunian0710@gmail.com
//        Company:  Class 1204 of Computer Science and Technology
// 
// =====================================================================================

#include "../myMutex.h"
#include "../myMutex.cpp"

pthread_mutex_t test_mutex;
pthread_t test_thread;

using namespace gaoyuan;
using std::cout;
using std::endl;

static void *test(void *ptr) {
	MyMutex::mutex_lock(&test_mutex);
	cout << "thread test " << endl;
	MyMutex::mutex_unlock(&test_mutex);
}

int main(int argc, char *argv[])
{


	MyMutex::mutex_init(&test_mutex);
	MyMutex::mutex_lock(&test_mutex);

	cout << "Main lock" << endl;

	pthread_create(&test_thread, NULL, test, NULL);
	sleep(1);
	cout << "Main unlock" << endl;
	pthread_mutex_unlock(&test_mutex);

	sleep(1);
	pthread_join(test_thread, NULL);
	MyMutex::mutex_destory(&test_mutex);


	return 0;
}

