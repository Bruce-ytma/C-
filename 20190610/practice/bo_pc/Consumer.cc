///*************************************************************************
///     @FileName: Consumer.cc
///     @Author:   ytma
///     @Email:    1539447319@qq.com
///     @Time:     2019-06-10 23:26:44
///*************************************************************************
#include "Consumer.h"
#include "TaskQueue.h"
#include <unistd.h>
#include <iostream>
using namespace std;

namespace wd
{
void Consumer::get(TaskQueue &taskque)
{
    int cnt=10;
    while(cnt--)
    {
        int number=taskque.pop();
        cout<<"consumer sub thread"<<pthread_self()
            <<">>consumer get a number="<<number<<endl;
        ::sleep(2);
    }
}

}//end of namespace wd


