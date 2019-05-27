//
//深拷贝
//必须显示的定义拷贝构造函数，它除了会将原有对象的所有成员
//变量拷贝给新对象，还会为新对象在分配一块内存，并将原有对象
//所持有的内存也拷贝过来。
//结果：原有对象和新对象所持有的动态内存是相互独立的，更改
//一个对象的数据不会影响另外一个对象。
#include<stdlib.h>
#include<string.h>
#include <iostream>
using std::cout;
using std::endl;

class Array
{
public:
    Array(int len);
    Array(const Array &arr);//拷贝构造函数声明
    ~Array();

    int operator[](int i)const//获取元素(读取)
    {
        return _p[i];
    }

    int &operator[](int i)//获取元素
    {
        return _p[i];
    }

    int length()const
    {
        return _len;
    }
private:
    int _len;
    int *_p;
};

Array::Array(int len)
    :_len(len)
{
    _p=(int *)calloc(len,sizeof(int));
    cout<<"Array(int)"<<endl;
}

Array::Array(const Array &arr)//拷贝构造函数
{
    this->_len=arr._len;
    this->_p=(int *)calloc(this->_len,sizeof(int));
    memcpy(this->_p,arr._p,_len*sizeof(int));
}

Array::~Array()
{
    free(_p);
}

//打印数组元素
void printArray(const Array &arr)
{
    int len=arr.length();
    for(int idx=0;idx<len;idx++)
    {
        if(idx=len-1)
        {
            cout<<arr[idx]<<endl;
        }
        else
        {
            cout<<arr[idx]<<",";
        }
    }
}

int main()
{
    Array arr1(10);
    for(int idx=0;idx<10;idx++)
    {
        arr1[idx]=idx;
    }

    Array arr2=arr1;//深拷贝
    arr2[5]=100;
    arr2[3]=29;

    printArray(arr1);
    printArray(arr2);
    return 0;
}

