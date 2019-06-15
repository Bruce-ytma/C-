///*************************************************************************
///     @FileName: TestEventfd.cc
///     @Author:   ytma
///     @Email:    1539447319@qq.com
///     @Time:     2019-06-14 20:48:18
///*************************************************************************
#include "EventfdThread.h"
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <functional>
using namespace std;

struct Mytask
{
    void process()
    {
        ::srand(::time(NULL));
        int number=::rand()%100;
        cout<<">>thread"<<pthread_self()
            <<":get a number="<<number<<endl;
    }
};

int main()
{
    wd::EventfdThread eventfd(bind(&Mytask::process,Mytask()));
    eventfd.start();
    
    int cnt=20;
    while(cnt--)
    {
        cout<<"cnt="<<cnt<<endl
            <<">>main thread notify sub thread to do something..."<<endl;
        eventfd.wakeup();
        ::sleep(1);
    }

    //::sleep(2);
    cout<<">>main thread eventfd stop..."<<endl;
    eventfd.stop();

    return 0;
}

