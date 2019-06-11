///*************************************************************************
///     @FileName: TestThread.cc
///     @Author:   ytma
///     @Email:    1539447319@qq.com
///     @Time:     2019-06-10 17:11:24
///*************************************************************************
#include "Thread.h"
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <memory>
using namespace std;

class MyTask
{
public:
    ~MyTask()
    {
        cout<<"~MyTask()"<<endl;
    }

    void process()
    {
        ::srand(::clock());
        int cnt=10;
        while(cnt--)
        {
            int number=::rand()%100;
            cout<<">>sub thread"<<pthread_self()
                <<":get a number="<<number<<endl;
            ::sleep(1);
        }
    }
};

int main()
{
    cout<<">>main thread"<<pthread_self()<<endl;
    MyTask task;

    //如果是以指针的方式传递对象，要保障证在执行process方法时，
    //该对象生命周期没有结束；如果结束，执行时会出错
    //绑定对象时，也可以以值传递方式传递对象
    unique_ptr<wd::Thread> mythread(new wd::Thread(std::bind(&MyTask::process,task)));
    mythread->start();
    mythread->join();
    return 0;
}

