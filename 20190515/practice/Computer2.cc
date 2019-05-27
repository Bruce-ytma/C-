#include"Computer2.h"
#include<string.h>
#include <iostream>
using std::cout;
using std::endl;

void Computer::setBrand(const char *brand)
{
    strcpy(_brand,brand);
}

void Computer::setPrice(float price)
{
    _price=price;
}

void Computer::print()
{
    cout<<"brand:"<<_brand<<endl
        <<"price:"<<_price<<endl;
}

int main()
{
    int number;
    Computer pc;
    pc.setBrand("AppleMacbookPro");
    pc.setPrice(17000);
    pc.print();

    //pc.price=100;//error private型成员不能再类之外访问
    //pc.brand=0x100;//error protected型成员不能在类之外访问

    return 0;
}

