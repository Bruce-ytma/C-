//
//公有继承
//
//公有继承时，基类的公用成员和保护成员在派生类中保持
//原有的访问属性，其私有成员仍为基类私有，即在派生类
//中不能访问，在类外也不能访问。
#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
    Base(int pub=0,int pro=0,int pri=0)
        :_pub(pub)
        ,_pro(pro)
        ,_pri(pri)
    {
        cout<<"Base()"<<endl;
    }
    ~Base()
    {
        cout<<"~Base()"<<endl;
    }

    void Print()
    {
        cout<<"Base::Print()"<<endl;
    }

    int _pub;
protected:
    int _pro;
private:
    int _pri;
};

class Derive:public Base
{
public:
    Derive()
    {
        cout<<"Derive()"<<endl;
    }

    ~Derive()
    {
        cout<<"~Derive()"<<endl;
    }

    void Display()
    {
        cout<<"_pub="<<_pub<<endl;
        cout<<"_pro="<<_pro<<endl;
        //cout<<"_pri="<<_pri<<endl;//基类的私有成员不能访问
        cout<<"d_pro="<<d_pro<<endl;
        cout<<"d_pri="<<d_pri<<endl;
    }
    int d_pub;
protected:
    int d_pro;
private:
    int d_pri;
};
int main()
{
    Derive p;
    p.Display();
    p.Print();
    return 0;
}

