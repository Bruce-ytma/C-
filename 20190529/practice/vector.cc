//
//vector容器的使用、创建及初始化
//
#include<string.h>
#include <iostream>
#include<vector>
#include<algorithm>
#include<utility>
using std::cout;
using std::endl;
using std::vector;
using std::string;

void test0()
{
    vector<int>values1(20);//创建一个大小为20个元素的vector容器，默认初始化为0
    vector<double>values2{1,2,3,4,5};//使用初始化列表指定初始值及元素的个数
    //vector<string>values3(10,3);//创建一个大小为10个元素的容器，并且初始化为3
    
    //对于vector来说，可以调用size()和capacity()函数来得到它的大小和容量
    cout<<"The size is:"<<values1.size()<<endl;//大小为20
    cout<<"The capacity is:"<<values1.capacity()<<endl;//容量为20

    values1.push_back(1);
    cout<<"The size is:"<<values1.size()<<endl;//大小为21
    cout<<"The capacity is:"<<values1.capacity()<<endl;//容量变为40

    auto it=values1.size();
    cout<<"it="<<it<<endl;

    for(auto &it:values1)//通过循环遍历vector
    {
        it*=2;
    }

    //resize的三种用法
    values1.resize(25);
    cout<<"The size is:"<<values1.size()<<endl;//大小为25
    values1.resize(30,99);
    cout<<"The size is:"<<values1.size()<<endl;//大小为30
    values1.resize(10);
    cout<<"The size is:"<<values1.size()<<endl;//大小为10
    
    values1[0]=3;
    values1[9]=10;
    //front和back函数分别返回第一个和最后一个元素的引用
    cout<<"The front is:"<<values1.front()<<endl;
    cout<<"The back is:"<<values1.back()<<endl;

    auto pData=values1.data();//成员函数data()返回指向数组的指针
    cout<<"pData="<<pData<<endl;
}

void test1()
{
    vector<double>values;
    values.push_back(3.1415);
    values.emplace_back(2.345);//向容器中添加元素，比push_back的效率高
    
}

void test2()
{
    vector<int> data(100,99);
    data.pop_back();//删除最后一个元素
    cout<<"size:"<<data.size()<<endl;
    data.clear();//删除所有元素
    cout<<"size:"<<data.size()<<endl;
    //std::swap(std::begin(data)+1,std::end(data)-1);//第二个元素和最后一个元素交换
    //data.pop_back();//所以就删除了第二个元素
    //cout<<"size:"<<data.size()<<endl;
    data.shrink_to_fit();
    cout<<"capacity:"<<data.capacity()<<endl;
}

int main()
{
    //test0();
    //test1();
    test2();
    return 0;
}

