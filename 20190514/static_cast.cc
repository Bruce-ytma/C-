//
//强制类型转换
//

#include <iostream>
using std::cout;
using std::endl;

int test0()
{
    //c强制转换
    double x=1.11;
    //int y=x;
    int y=(int)x;
    int z=int(x);//强制转换
    cout<<"y="<<y<<endl;
    cout<<"z="<<z<<endl;

    int *pInt=(int *)malloc(sizeof(int));
    return 0;
}

int test1()
{
    //c++强制转换
    double x=1.11;
    //int y=x;
    int y=static_cast<int>(x);//c++强制转换(将x转换成int型，静态转换)
    cout<<"y="<<y<<endl;
    //cout<<"z="<<z<<endl;
    
    int *pInt=static_cast<int *>(malloc(sizeof(int)));
    return 0;
}

int main()
{
    //test0();
    test1();
    return 0;
}
