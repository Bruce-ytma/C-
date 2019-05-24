//
//在类中定义同名成员，使内层函数覆盖外层的函数
//
#include <iostream>
using std::cout;
using std::endl;

class Base1
{
public:
    void func()
    {
        cout<<"Base1::func()"<<endl;
    }
};

class Base2
{
public:
    void func()
    {
        cout<<"Base2::func()"<<endl;
    }
};

class Derived:public Base1,public Base2
{
public:
    Derived()
    {
        cout<<"Derived()"<<endl;
    }

    void func()
    {
        cout<<"Derived::func()"<<endl;
    }
};

int main()
{
    Derived obj;
    obj.func();//调用派生类的func()函数，覆盖了基类中的func()函数
    //obj.Base1::func();
    //obj.Base2::func();
    return 0;
}

