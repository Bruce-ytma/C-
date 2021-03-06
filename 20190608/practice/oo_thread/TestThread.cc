///*************************************************************************
///     @FileName: TestThread.cc
///     @Author:   ytma
///     @Email:    1539447319@qq.com
///     @Time:     2019-06-10 16:39:07
///*************************************************************************
#include "Noncopyable.h"
#include "Thread.h"
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <memory>
using namespace std;

class Mythread:public wd::Thread
{
public:
    ~Mythread()
    {
        cout<<"~Mypthread()"<<endl;
    }
private:
    void run()override
    {
        ::srand(::clock());
        int cnt=10;
        while(cnt--)
        {
            int number=::rand()%100;
            cout<<"sub thread"<<pthread_self()
                <<":get a number="<<number<<endl;
            ::sleep(1);
        }
    }
};

int main()
{
    //Mythread thread1;
    //Mythread thread2(thread1);

    cout<<">> main thread"<<pthread_self()<<endl;

    unique_ptr<wd::Thread> mythread(new Mythread());
    mythread->start();
    mythread->join();
    return 0;
}

