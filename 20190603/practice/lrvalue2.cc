///*************************************************************************
///     @FileName: lrvalue2.cc
///     @Author:   ytma
///     @Email:    1539447319@qq.com
///     @Time:   Mon 03 Jun 2019 09:32:19 PM CST
///*************************************************************************
#include <iostream>
#include <string>
#include <utility>
using namespace std;

void func(int &x)
{
    cout<<"func(int &)"<<endl;
}

void func(const int &x)
{
    cout<<"func(const int &)"<<endl;
}

void func(int &&x)
{
    cout<<"func(int &&)"<<endl;
}

void test0()
{
    string s1="Test";
    //string &r2=s1+s1;// error 不能将表达式绑定到左值
    const string &r2=s1+s1;//对const左值引用延长了生命周期
    //r2+="Test";//error 不能通过引用修改const引用
    string &&r3=s1+s1;//对右值引用延长了生命周期
    r3+="Test";
    cout<<r3<<endl;

    //更重要的是，当函数同时具有rvalue引用和左值引用重载时
    //rvalue引用重载绑定到rvalues，而lvalue引用重载绑定到lvalues
    int i=1;
    const int ci=2;
    func(i);
    func(ci);
    func(3);
}

int main()
{
    test0();
    return 0;
}

