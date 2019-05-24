#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
    virtual void f(float x)
    {
        cout<<"Base::f(float)"<<x<<endl;
    }

    void g(float x)
    {
        cout<<"Base::g(float)"<<x<<endl;
    }

    void h(float x)
    {
        cout<<"Base::h(float)"<<x<<endl;
    }
};

class Derived:public Base
{
public:
    virtual void f(float x)
    {
        cout<<"Derived::f(float)"<<x<<endl;//多态，覆盖
    }

    void g(int x)
    {
        cout<<"Derived::g(int)"<<x<<endl;//隐藏
    }

    void h(float x)
    {
        cout<<"Derived::h(float)"<<x<<endl;//隐藏
    }
};

int main()
{
    Derived d;
    Base *pb=&d;
    pb->f(3.14f);//Derived::f(float) 3.14
    pb->f(3.14f);//Derived::f(float) 3.14

    pb->g(3.14f);//Base::g(float) 3.14
    pb->g(3.14f);//Base::g(float) 3.14
    pb->g(3);//Base::g(float)3

    pb->h(3.14f);//Base::h(float) 3.14
    pb->h(3.14f);//Base::h(float) 3.14
    return 0;
}

