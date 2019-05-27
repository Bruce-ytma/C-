//
//动态多态
//
#include <iostream>
using std::cout;
using std::endl;

class A
{
public:
    A()
    {
        cout<<"A()"<<endl;
    }

    virtual void f()
    {
        cout<<"A::f()"<<endl;
    }
};

class B:public A
{
public:
    B()
    {
        cout<<"B()"<<endl;
    }

    virtual void f()
    {
        cout<<"B::f()"<<endl;
    }
};

int main()
{
    A a;
    B b;

    A *p1=&a;
    A *p2=&b;

    p1->f();
    p2->f();
    return 0;
}

