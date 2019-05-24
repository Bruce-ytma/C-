//
//c++函数重载
//
#include <iostream>
using std::cout;
using std::endl;

//c++语言本身支持函数重载
//实现原理：名字改编(name mangling)
//具体的操作步骤：当函数名字相同时，根据参数的类型，顺序，个数的不同进行改编

int add(int x,int y)
{
    return x+y;
}

double add(double x,double y)
{
    return x+y;
}

double add(int x,double y)
{
    return x+y;
}

double add(double x,int y)
{
    return x+y;
}

int add(int x,int y,int z)
{
    return x+y+z;
}

int main()
{
    int a=3,b=4,c=5;
    printf("a+b=%d\n",add(a,b));
    printf("a+b+c=%d\n",add(a,b,c));
    return 0;
}

