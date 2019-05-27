//
//用=给对象之间的赋值
//
#include <iostream>
using std::cout;
using std::endl;

class Demo
{
public:
    Demo()
        :_a(0)
        ,_b(0)
    {
        cout<<"Demo()"<<endl;
    }

    Demo(int a,int b)
        :_a(a)
        ,_b(b)
    {
        cout<<"Demo(int,int)"<<endl;
    }

    void display()
    {
        cout<<"a="<<_a<<endl
            <<"b="<<_b<<endl;
    }
private:
    int _a;
    int _b;
};

int main()
{
    Demo obj1(10,20);
    Demo obj2=obj1;//对象之间的赋值

    obj1.display();
    obj2.display();
    return 0;
}

