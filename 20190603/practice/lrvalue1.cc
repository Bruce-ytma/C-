///*************************************************************************
///     @FileName: lrvalue.cc
///     @Author:   ytma
///     @Email:    1539447319@qq.com
///     @Time:   Mon 03 Jun 2019 08:39:58 PM CST
///*************************************************************************
#include <iostream>
#include <string>
#include <utility>
using namespace std;

char &get_val(string &str,string::size_type ix)
{
    return str[ix];
}

void test0()
{
    //赋值运算符的左值运算对象必须是一个可修改的左值
    int i=0,j=0,k=0;//初始化
    const int ci=i;//初始化

    //1024=k;//error 字面值是右值
    //i+j=k;//error 算数表达式是右值
    //ci=k;//error ci是常量左值
}

void test1()
{
    int i=0;
    int &r=i;//r引用i
    //int &&rr=i;//error 不能将一个右值引用绑定到左值上
    //int &r2=i*42;//error i*42是一个右值
    const int &r3=i*42;//可以将一个const引用绑定到一个右值上
    int &&rr2=i*42;//ok
}

void test2()
{
    //不能将一个右值引用绑定到一个右值引用的类型上
    int &&rr1=42;//字面常量是右值
    //int &&rr2=rr1;//rr1是左值
    //int rr=&&rr1;//不能将一个右值引用绑定到左值上
    int i=5;
    int &&rr3=move(i);//std::move可以显示的将一个左值转换为对应的右值类型
        

    //调用一个返回引用的函数得到左值，其他返回类型得到左值
    string s{"a value."};
    cout<<s<<endl;
    get_val(s,0)='A';
    cout<<s<<endl;

}

int main()
{
    test0();
    test1();
    test2();
    return 0;
}

