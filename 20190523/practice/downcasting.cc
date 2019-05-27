//
//向下转型:用派生类指针指向基类对象
//
#include <iostream>
using std::cout;
using std::endl;

class A
{
public:
    A(int a1,int a2);
    void display();
protected:
    int m_a1;
    int m_a2;
};

A::A(int a1,int a2)
    :m_a1(a1)
    ,m_a2(a2)
{
    cout<<"A::A(int,int)"<<endl;
}

void A::display()
{
    cout<<"m_a1="<<m_a1<<endl
        <<"m_a2="<<m_a2<<endl;
}

class B:public A
{
public:
    B(int a1,int a2,int b);
    void display();
private:
    int m_b;
};

B::B(int a1,int a2,int b)
    :A(a1,a2)
    ,m_b(b)
{
    cout<<"B::B(int,int,int)"<<endl;
}

void B::display()
{
    cout<<"m_a1="<<m_a1<<endl
        <<"m_a2="<<m_a2<<endl
        <<"m_b="<<m_b<<endl;
}

int main()
{
    B *p=(B *)new A(1,2);
    p->display();
    return 0;
}

