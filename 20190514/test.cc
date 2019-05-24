#include"inline2.h"//使用双引号查找文件时，会从当前路径下查找
                   //当前路径下找不到时，接着去系统路径下查找
#include <iostream>//使用尖括号时，查找头文件时，直接从系统路径下查找
using std::cout;
using std::endl;

int main()
{
    int x1=3,x2=4;
    cout<<"max(x1,x2)="<<max(x1,x2)<<endl;
    return 0;
}

