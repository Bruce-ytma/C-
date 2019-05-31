/*************************************************************************
  @FileName: funcObject2.cc
  @Author:   ytma
  @Email:    1539447319@qq.com
  @Time:   Fri 31 May 2019 07:44:01 PM CST
 ************************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>
using namespace std;

template<typename T>
class Print
{
public:
    int ret=0;
    void operator()(T i)
    {
        cout<<i<<" ";
        ret++;
    }
};

class Compare
{
public:
    bool operator()(int i)
    {
        return i>7;
    }
};

class Sort_int
{
public:
    bool operator()(int v1,int v2)
    {
        return v1>v2;
    }
};

void test0()
{
    vector<int> v;
    for(int i=0;i<100;i++)
    {
        v.push_back(i+1);
    }
    Print<int> print_int;
    print_int=for_each(v.begin(),v.end(),print_int);
    cout<<endl;
    cout<<print_int.ret<<endl;
}

void test1()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(7);
    v.push_back(8);
    vector<int>::iterator it;
    it=find_if(v.begin(),v.end(),Compare());
    if(it==v.end())
    {
        cout<<"Can not find."<<endl;
    }
    else
    {
        cout<<"Find."<<endl;
    }
}

void test2()
{
    vector<int> v1,v2,v3;
    for(int i=0;i<10;i++)
    {
        v1.push_back(i);
        v2.push_back(i+1);
    }
    //transform对两个容器进行操作，将结果存放在第三个容器里
    //v3在transform之前要先开辟内存空间
    v3.resize(100);
    transform(v1.begin(),v1.end(),v2.begin(),v3.begin(),plus<int>());

    for(int i=0;i<v3.size();i++)
    {
        cout<<v3.at(i)<<" ";
    }
    cout<<endl;
}

void test3()
{
    vector<int> v1;
    v1.push_back(3);
    v1.push_back(2);
    v1.push_back(9);
    v1.push_back(6);
    for_each(v1.begin(),v1.end(),Print<int>());
    cout<<endl;
    sort(v1.begin(),v1.end(),Sort_int());
    for_each(v1.begin(),v1.end(),Print<int>());
    cout<<endl;
}

int main()
{
    //test0();
    //test1();
    //test2();
    test3();
    return 0;
}

