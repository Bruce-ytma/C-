//
//成员名访问冲突的二义性：--> 通过作用域限定符解决
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
};

int main()
{
    Derived obj;
    //obj.func();//产生歧义
    obj.Base1::func();
    obj.Base2::func();
    return 0;
}

