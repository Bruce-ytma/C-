//
//虚函数用法1：
//
#include <iostream>
using std::cout;
using std::endl;

class A
{
public:
    virtual void display()
    {
        cout<<"A::display()"<<endl;
    }
};

class B:public A
{
public:
    virtual void display()
    {
        cout<<"B::display()"<<endl;
    }
};

void display(A *p)
{
    p->display();
    delete p;
}

int main()
{
    A p1;
    p1.display();//输出结果：A::display()
    display(new B());//输出结果：B::display()
    //A *p;
    //p->display();//error
    return 0;
}

