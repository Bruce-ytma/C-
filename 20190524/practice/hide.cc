//
//隐藏
//
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
        cout<<"Derived::f(float)"<<x<<endl;
    }

    void g(int x)
    {
        cout<<"Derived::g(int)"<<x<<endl;
    }

    void h(float x)
    {
        cout<<"Derived::h(float)"<<x<<endl;
    }
};

int main()
{

    Derived d;
    Base *pb=&d;
    Derived *pd=&d;

    //
    //行为取决于对象地类型
    //虚函数
    pb->f(3.14f);//输出结果：Derived::f(float)3.14
    pd->f(3.14f);//输出结果：Derived::f(float)3.14

    //如果派生类的函数与基类的函数同名，但是参数不同。
    //此时，不论有无virtual关键字，基类的函数将被隐藏。(别与重载混淆)
    //
    //行为取决于指针的类型
    pb->g(3.14f);//输出结果：Base::g(float)3.14
    //函数Derived::g(int)隐藏了Base::g(float),不是重载
    pd->g(3.14f);//输出结果：Derived::g(int)3

    //如果派生类的函数与基类的函数同名，并且参数也相同，但是基类函数没有
    //virtual关键字。此时，基类的函数被隐藏(注意不要与覆盖混淆)
    //
    //行为取决于指针的类型
    pb->h(3.14f);//输出结果：Base::h(float)3.14
    //函数Derived::h(float)隐藏了函数Base::h(float),不是覆盖
    pd->h(3.14f);//输出结果：Derived::h(float)3.14
    return 0;
}

