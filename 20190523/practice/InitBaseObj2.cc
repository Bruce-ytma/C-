//
//在派生类中成员初始化列表先初始化派生类的私有成员，
//不显示的调用基类的构造函数，则会调用默认构造函数
//
#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
    Base()
    {
        cout<<"Base()"<<endl;
    }

    Base(int num)
        :_num(num)
    {
        cout<<"Base(int)"<<endl;
    }
    
    ~Base()
    {
        cout<<"~Base()"<<endl;
    }
private:
    int _num;
};

class Derived:public Base
{
public:
    Derived(int num)
        :_num(num)
    {
        cout<<"Derived(int)"<<endl;
    }

    ~Derived()
    {
        cout<<"~Derived()"<<endl;
    }
private:
    int _num;
};

int main()
{
    Derived *pd=new Derived(10);
    return 0;
}

