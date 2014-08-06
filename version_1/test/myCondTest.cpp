// =====================================================================================
// 
//       Filename:  myCondTest.cpp
//
//    Description:  
//
//        Version:  1.0
//        Created:  2014年05月01日 21时16分24秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Gaoyuan, sishuiliunian0710@gmail.com
//        Company:  Class 1204 of Computer Science and Technology
// 
// =====================================================================================

#include "../myCond.h"
#include "../myCond.cpp"
#include "../myMutex.h"
#include "../myMutex.cpp"

using namespace gaoyuan;

pthread_mutex_t test_mutex;
pthread_cond_t test_cond;

int count = 0;

void *decrement_count(void *arg) {	
	MyMutex::mutex_lock(&test_mutex);
	cout << "The process decrement get lock" << endl;

	while (0 == count) {
		cout << "decrement count == 0" << endl;
		cout << "decrement count before wait " << endl;
		MyCond::cond_wait(&test_cond, &test_mutex);
		cout << "decrement count after wait " << endl;
	}
	count ++;
	MyMutex::mutex_unlock(&test_mutex);
}
void *increment_count(void* argv) {
	MyMutex::mutex_lock(&test_mutex);
	cout << "increment count get lock" << endl;

	if (0 == count ) {
		cout << "increment count befor signal " << endl;
		MyCond::cond_signal(&test_cond);
		cout << "increment count after signal " << endl;
	}

	count++;
	MyMutex::mutex_unlock(&test_mutex);
}

int main(int argc, char *argv[])
{
	pthread_t thread1, thread2;

	MyMutex::mutex_init(&test_mutex);
	MyCond::cond_init(&test_cond);

	pthread_create(&thread1, NULL, decrement_count, NULL);
	sleep(2);
	pthread_create(&thread2, NULL, increment_count, NULL);

	sleep(10);
	pthread_exit(0);


	return 0;
}

