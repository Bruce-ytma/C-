#include<string.h>
#include<iostream>


class Computer
{
public://类提供的接口、功能、服务
    //在类内部实现的函数都是inline函数
    void setBrand(const char *brand);
    void setPrice(float price);
    void print();
protected://受保护的成员只会对其派生类或者子类开放
    char _brand[20];
private://被封装的信息
    //private型成员自定义时在前面加上下划线
    float _price; 
};
