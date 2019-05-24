#include <iostream>
using std::cout;
using std::endl;

class A
{
public:
    void foo()
    {
        cout<<"A:void foo()"<<endl;
    }

    virtual void fun()
    {
        cout<<"A:virtual void fun()"<<endl;
    }
};

class B:public A
{
public:
    void foo()//隐藏：派生类的函数屏蔽了与其同名的基类函数
    {
        cout<<"B:void foo()"<<endl;
    }

    void fun()//多态，覆盖
    {
        cout<<"B:void fun()"<<endl;
    }
};

int main()
{
    A a;
    B b;
    A *p=&a;
    p->foo();//输出:A:void foo()
    p->fun();//输出:A:virtual void fun()

    p=&b;
    p->foo();//取决于指针类型，输出:A:void foo()
    p->fun();//取决于指针对象类型，输出:B:void fun(),体现了多态
    
    //B *ptr=(B *)&a;
    //ptr->foo();
    //ptr->A::fun();
    return 0;
}

