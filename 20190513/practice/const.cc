#include <iostream>
using std::cout;
using std::endl;

//const常量和#define定义常量的区别：
//宏定义发生时机：预处理，仅仅只是字符串的替换
//
//const关键字代表的常量发生时机：编译，是有类型检查
//定义常量时，多用const替换宏定义，可以降低犯错误的概率

void test0()
{
    const int number=10;//初始化
    //const int number;//error 未初始化(常量必须要初始化)
    int number2;//未初始化
    //int number3=1;//初始化
    //int number4(0);//c++独有的初始化方式
    std::string s1("hello");
    cout<<"number="<<number<<endl;
    number2=1;
    cout<<"number2="<<number2<<endl;
    cout<<"s1="<<s1<<endl;
    //number=11;//赋值
}

void test1()
{
    int number=1;
    int number2=11;
    const int *p=&number;//常量指针(pointer to const)
    //*p=10;//error 不能通过指针修改number的值
    cout<<"p="<<p<<endl;//p改变之前number的地址
    p=&number2;//但是可以改变指向
    cout<<"p="<<p<<endl;//p改变之后number的地址
    //number=111;
    cout<<"number="<<number<<endl;
    cout<<"*p="<<*p<<endl;

    int const *p2=&number;//同p一样
    //*p2=111;//error 不能通过p2改变number的值
    p2=&number;//但是可以通过p2改变指向
    cout<<"number="<<number<<endl;
    cout<<"*p2="<<*p2<<endl;

    int *const p3=&number;//指针常量(const pointer)
    *p3=111;//可以通过p3改变number的值
    //p3=&number2;//error 但是不能通过p3改变指向
    cout<<"number="<<number<<endl;
    cout<<"*p3="<<*p3<<endl;
    cout<<"p3="<<p3<<endl;
}

int main()
{
    //test0();
    test1();
    return 0;
}

