//
//将派生类对象赋值给基类对象
//
#include <iostream>
using std::cout;
using std::endl;

class A
{
public:
    A(int a);
    void display();
    int m_a;
};

A::A(int a)
    :m_a(a)
{
    cout<<"A(int)"<<endl;
}

void A::display()
{
    cout<<"class A:m_a="<<m_a<<endl;
}

class B:public A
{
public:
    B(int a,int b);
    void display();
    int m_b;
};

B::B(int a,int b)
    :A(a)
    ,m_b(b)
{
    cout<<"B(int,int)"<<endl;
}

void B::display()
{
    A::display();
    cout<<"class B:m_b="<<m_b<<endl;
}

int main()
{
    A a(10);
    B b(66,99);

    a.display();
    b.display();
    
    a=b;
    a.display();
    b.display();
    return 0;
}

