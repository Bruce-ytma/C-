//
//私有继承
//
#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
    Base(int a = 0,int b = 0,int c = 0)
        :_pub(a)
         , _pro(b)
         , _pri(c)
    {
        cout << "Base()" << endl;

    }
    ~Base()
    {
        cout << "~Base()" << endl;

    }
    int _pub;
protected:
    int _pro;
private:
    int _pri;

};
class Derive :private Base
{
public:
    Derive()
    {}
    ~Derive()
    {}
    void Display()
    {
        //cout << "_pri" << _pri << endl;//会报错
        //父类的是私有的
        //相当于在类外访问私有成员
        cout << "_pro=" << _pro << endl;//私有继承中，派生类可以访问基类的public和protected
        cout << "_pub=" << _pub << endl;
        //_pro,_pub均为protected属性，可以类内访问
        cout << "d_pri=" << d_pri << endl;
        cout << "d_pro=" << d_pri << endl;
        cout << "d_pub=" << d_pri << endl;                           
    }
private:
    int d_pri;
protected:
    int d_pro;
public:
    int d_a;

};
int main()
{
    Derive a;
    a.Display();
    //a._pro = 0;
    //a._pub = 0;
    //上面两句均会报错，因为_pro,_pub均为private属性的成员
    //    //不能在类外访问
    //    
}
