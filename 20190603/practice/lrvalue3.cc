///*************************************************************************
///     @FileName: lrvalue3.cc
///     @Author:   ytma
///     @Email:    1539447319@qq.com
///     @Time:   Mon 03 Jun 2019 10:02:31 PM CST
///*************************************************************************
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int a=1;
    int b=2;

    &a;
    &b;
    //&(a+b);//右值
    
    //&(a++);//后置形式是右值
    &(++a);//前置形式是左值
    vector<int> numbers;
    &numbers;
    numbers.push_back(1);
    &numbers[0];

    //&100;//字面常量值是右值
    //&string("hello");//右值，匿名对象
    string str1("hello");
    string str2("world");
    //&&(str1+str2);//右值
    
    const int &m=100;//在c++11之前，只有const引用能绑定到右值
    &m;//左值
    const int &n=a;//const同时还能绑定到左值

    //右值引用c++11
    int &&ref1=100;//右值引用可以绑定到右值
    //int &&ref2=a;//error 右值引用不能绑定到左值
    
    const int &&ref3=100;//使用右值引用就意味着修改
                         //右值引用加上const没有意义
    return 0;
}

