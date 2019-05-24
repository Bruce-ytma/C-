//
//存储二义性问题(菱形继承)：--> 采用虚拟继承
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

class Derived11:virtual public Base//class Derived11:public Base产生二义性
{
public:
    Derived11()
    {
        cout<<"Derived11()"<<endl;
    }
};

class Derived12:virtual public Base//class Derived11:public Base产生二义性
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
    obj.data=1;//产生二义性的最主要的原因就是base在
               //派生类Derived2中产生了2个对象，从而
               //导致了对基类Base的成员data访问的不一致性。
               //要解决这个问题，只需使这个公共基类Base在
               //派生类中只产生一个子对象即可
    cout<<"obj.data="<<obj.data<<endl;
    return 0;
}

