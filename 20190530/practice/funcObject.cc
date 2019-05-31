/*************************************************************************
  @FileName: funcObject.cc
  @Author:   ytma
  @Email:    1539447319@qq.com
  @Time:   Fri 31 May 2019 05:29:14 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
using namespace std;

class Compare
{
public:
    int cnt=0;//记录函数调用次数
    bool operator()(int i,int j)
    {
        this->cnt++;
        return i>j;
    }
};

bool compareFun(int i,int j)
{
    return i>j;
}

//函数对象：函数对象本质上是一个类而不是一个函数
void test0()
{
    Compare a,b;
    cout<<a(1,2)<<" "<<compareFun(1,2)<<endl;
    cout<<b(4,3)<<" "<<compareFun(2,1)<<endl;
    a(3,4);
    a(5,6);
    a(7,8);
    cout<<"函数对象a调用次数："<<a.cnt<<" "<<"函数对象b调用次数："<<b.cnt<<endl;
}

//利用for_each()实现打印vector中的所有元素
class Print
{
public:
    int cnt=0;
    void operator()(int i)
    {
        cout<<i<<" ";
        cnt++;
    }
};

void test1()
{
    vector<int> v;
    for(int i=0;i<10;i++)
    {
        v.push_back(i);
    }
    Print p1;
    p1=for_each(v.begin(),v.end(),p1);
    cout<<endl;
    cout<<p1.cnt<<endl;
}

//STL封装的函数对象的用法
void test2()
{
    plus<int> plus_int;
    int ret=plus_int(10,20);
    cout<<ret<<endl;

    plus<string> plus_str;
    string a="aaa";
    string b="bbb";
    string c=plus_str(a,b);
    cout<<c<<endl;

    cout<<plus<int>()(1,2)<<endl;//匿名对象
}

int main()
{
    //test0();
    //test1();
    test2();
    return 0;
}
