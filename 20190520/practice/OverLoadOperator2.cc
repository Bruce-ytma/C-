///*************************************************************************
///     @FileName: OverLoadOperator2.cc
///     @Author:   ytma
///     @Email:    1539447319@qq.com
///     @Time:     2019-06-07 15:51:46
///*************************************************************************
#include <iostream>
using namespace std;

class A
{
public:
    friend A operator+(A &,A &);
    A()=default;
    A(int x)
        :_a(x)
    {
        cout<<"A(int)"<<endl;
    }
private:
    int _a;
};

A operator+(A &c,A &d)
{
    return A(c._a+d._a);
}

int main()
{
    A b,c,d;
    d=b+c;//等价于d=operator+(b,c)
    return 0;
}

