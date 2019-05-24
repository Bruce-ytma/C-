#include <iostream>
using std::cout;
using std::endl;

#define NUMBER 100
#define MAX(X,Y) (X>Y?X:Y)
#define MULTIPLY(X,Y) ((X)*(Y))

//inline的功能与带参数的宏定义相同
//减少函数调用的开销，但它比带参数的宏定义更安全
//有类型检查
//
//为了减少犯错误的概率，推荐使用inline函数

inline int max(int x,int y)
{
    return x>y?x:y;
}

int main()
{
    int a=3,b=4,c=5;
    cout<<"MAX(a,b)="<<MAX(a,b)<<endl;
    printf("MAX(a,b)=%d\n",MAX(a,b));
    printf("MAX(a,b+c)=%d\n",MAX(a,b+c));
    printf("MULTIPLY(a,b+c)=%d\n",MULTIPLY(a,b+c));
    return 0;
}

