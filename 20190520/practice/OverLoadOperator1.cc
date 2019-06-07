///*************************************************************************
///     @FileName: OverLoadOperator.cc
///     @Author:   ytma
///     @Email:    1539447319@qq.com
///     @Time:     2019-06-07 15:39:08
///*************************************************************************
#include <iostream>
using namespace std;

class A
{
public:
    A operator+(A &);
    A()=default;
    A(int x)
        :_a(x)
    {
        cout<<"A(int)"<<endl;
    }
private:
    int _a;
};

A A::operator+(A &d)
{
    return A(_a+d._a);
}

int main()
{
    A b,c,d;
    d=b+c;//等价于d=b.operator+(c)
    return 0;
}

