///*************************************************************************
///     @FileName: TestThreadpool.cc
///     @Author:   ytma
///     @Email:    1539447319@qq.com
///     @Time:     2019-06-11 22:35:44
///*************************************************************************
#include "Threadpool.h"
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

class Mytask
{
public:
    void process()
    {
        ::srand(::time(NULL));
        int number=::rand()%100;
        cout<<">>sub thread"<<pthread_self()
            <<"create a number="<<number<<endl;
        ::sleep(1);
    }
};

int main()
{
    wd::Threadpool threadpool(4,10);
    threadpool.start();
    int cnt=20;
    while(cnt--)
    {
        threadpool.addTask(bind(&Mytask::process,Mytask()));
        cout<<">>cnt="<<cnt<<endl;
    }
    threadpool.stop();
    return 0;
}

