///*************************************************************************
///     @FileName: TestFriend.cc
///     @Author:   ytma
///     @Email:    1539447319@qq.com
///     @Time:     2019-06-07 10:18:53
///*************************************************************************
#include <iostream>
using namespace std;

class A
{
public:
    A(int a)
        :_a(a)
    {
        cout<<"A(int)"<<endl;
    }

    friend int getA(A &classA);//友元函数
private:
    int _a;
};

int getA(A &classA)
{
    return classA._a;//通过对象名访问私有变量
}

int main()
{
    A classA(3);
    cout<<getA(classA)<<endl;//友元函数只是普通函数，可以在任意地方调用
    return 0;
}

