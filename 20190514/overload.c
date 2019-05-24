//
//函数重载
//c
//c语言本身并不支持函数重载
#include <stdio.h>

int add(int x,int y)
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
    return 0;
}

