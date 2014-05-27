// =====================================================================================
// 
//       Filename:  myWork.h
//
//    Description:  
//
//        Version:  1.0
//        Created:  2014年05月02日 21时26分42秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Gaoyuan, sishuiliunian0710@gmail.com
//        Company:  Class 1204 of Computer Science and Technology
// 
// =====================================================================================

#ifndef _MYWORK_H
#define _MYWORK_H

#include <iostream>

namespace gaoyuan{
void *work(void *arg);

class MyWork {
	public:
		MyWork(){}
		MyWork(void*(*work)(void *) = NULL, void *arg = NULL){
			this->work = work;
			this->arg = arg;
		}
//		void *get_job_name() {
//			return this->work;
//		}
//	private:
		void *(*work)(void *arg);
		void *arg;
};
}
#endif

