//
//浅拷贝
//
#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
    Base()
        :_a(0)
        ,_b(0)
    {
        cout<<"Base()"<<endl;
    }

    Base(int a,int b)
        :_a(a)
        ,_b(b)
    {
        cout<<"Base(int,int)"<<endl;
    }
private:
    int _a;
    int _b;
};

int main()
{
    int a=10;
    int b=a;//浅拷贝

    Base obj1(10,20);
    Base obj2=obj1;//浅拷贝
    return 0;
}

