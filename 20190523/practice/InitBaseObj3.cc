//
//派生类析构函数的调用过程中会自动去调用基类的析构函数，所以不要
//在派生类的析构函数中再去调用基类的析构函数，这种去释放已经释放
//的内存，系统是不允许的
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
        _num=8;
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
        :Base(num)
        ,_num(num)
    {
        cout<<"Derived()"<<endl;
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
    delete pd;
    return 0;
}

