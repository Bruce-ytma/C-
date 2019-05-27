#include<string.h>
#include <iostream>
using std::cout;
using std::endl;

//c++中的struct与class的差别只在默认访问权限
class X//class的默认访问权限是public
{
    int _ix;
};

//在函数对象中经常使用
struct Y
{
    int _iy;
    void display()
    {
        cout<<"Y::display()"<<endl;
    }
};

class Computer
{
public:
    //在类内部实现的函数都是inline函数
    void setBrand(const char *brand)
    {
        strcpy(_brand,brand);
    }
    void setPrice(float price)
    {
        _price=price;
    }
    void print()
    {
        cout<<"brand:"<<_brand<<endl
            <<"price:"<<_price<<endl;
    }
protected://受保护的成员只会对其派生类或者子类开放
    char _brand[20];
private:
    //private型成员自定义时在前面加上下划线
    float _price; 
};

int main()
{
    int number;
    Computer pc;
    pc.setBrand("AppleMacbookPro");
    pc.setPrice(17000);
    pc.print();

    //pc.price=100;//error private型成员不能再类之外访问
    //pc.brand=0x100;//error protected型成员不能在类之外访问
    
    X x;
    //cout<<"x="<<x._ix<<endl;
    Y y;
    cout<<"y="<<y._iy<<endl;

    return 0;
}

