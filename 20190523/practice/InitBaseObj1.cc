//
//在派生类成员初始化列表中先初始化派生类的私有成员，
//显示的调用基类的构造函数
#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
    Base(int num)
        :_num(num)
    {
        cout<<"Base()"<<endl;
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
    return 0;
}

