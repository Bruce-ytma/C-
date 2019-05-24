//
//           Base
//          /   \
//  Derived11     Derived12
//          \   /
//         Derived2
//
#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
    int data;
};

class Derived11:public Base
{
public:
    Derived11()
    {
        cout<<"Derived11()"<<endl;
    }
};

class Derived12:public Base
{
public:
    Derived12()
    {
        cout<<"Derived12()"<<endl;
    }
};

class Derived2:public Derived11,public Derived12
{
public:
    Derived2()
    {
        cout<<"Derived2()"<<endl;
    }
};

int main()
{
    Derived2 obj;
    //obj.data=1;//产生二义性
    //obj.Base::data=1;//由于派生类的直接基类有一个共同的基类，所以 obj.Base::a是错误的
    obj.Derived11::data=1;//指明清楚要访问的
    cout<<"obj.Derived11::data="<<obj.Derived11::data<<endl;
    return 0;
}

