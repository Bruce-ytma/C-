///*************************************************************************
///     @FileName: Producer.cc
///     @Author:   ytma
///     @Email:    1539447319@qq.com
///     @Time:     2019-06-11 21:12:29
///*************************************************************************
#include "Producer.h"
#include "TaskQueue.h"
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

namespace wd
{
void Producer::create(TaskQueue &taskque)
{
    ::srand(::clock());
    int cnt=10;
    while(cnt--)
    {
        int number=::rand()%100;
        taskque.push(number);
        cout<<">>producer sub thread"<<pthread_self()
            <<"producer create a number="<<number<<endl;
        //::usleep(2000);
        sleep(1);
    }
}
}//end of namespace wd


