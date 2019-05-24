#include<stdlib.h>//c的头文件放到c++的头文件上面 ，自定义的头文件写到最上面
#include<string.h>
#include <iostream>

using std::cout;
using std::endl;

void test0()
{
    int *pInt=(int *)malloc(sizeof(int));//malloc不会对申请的空间初始化
    //用memset或者bzero初始化申请的空间
    *pInt=10;//赋值
    cout <<"*pInt="<<*pInt<<endl;
    free(pInt);

    int *array=(int *)malloc(sizeof(int)*10);//申请一个数组
    memset(array,0,sizeof(int)*10);//初始化

    for(int idx=0;idx!=10;++idx)
    {
        array[idx]=idx;
    }

    for(int idx=0;idx!=10;++idx)
    {
        cout<<array[idx]<<" ";
    }
    cout<<endl;
    free(array);
    
    //加上防御性措施，防止出现野指针
    array=NULL;//c语言中防止array变成野指针，采取的的防御措施，将array赋为NULL
    array=nullptr;//c++中防止array变成野指针，采取的措施
    //如果在此之后，继续使用array，他就变成一个野指针
}

void test1()
{
    //申请空间（作用：1.申请空间；2.初始化空间；3.返回一个指针变量）
    int *pInt=new int(10);//执行new表达式时，就已经初始化完毕
    cout<<"*pInt="<<*pInt<<endl;
    delete pInt;//释放空间

    //int *pInt=new int[10];//只会申请空间，不会初始化
    int *pInt2=new int[10]();//可以申请空间，并且也可以初始化，初始化为0
    delete []pInt2;
}

void test2()
{
    int *p1;//野指针
    cout<<"p1="<<p1<<endl;
}
 
int main()
{
    //test0();
    //test1();
    test2();
    return 0;
}

