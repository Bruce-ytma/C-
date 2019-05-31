/*************************************************************************
  @FileName: unordered_set.cc
  @Author:   ytma
  @Email:    1539447319@qq.com
  @Time:   Thu 30 May 2019 09:43:40 PM CST
 ************************************************************************/
#include <iostream>
#include <unordered_set>
using namespace std;

void unorderedSet(unordered_set<int>&m,string pre)
{
    unordered_set<int>::iterator it;
    cout<<pre;
    for(it=m.begin();it!=m.end();++it)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}

void test0()
{
    unordered_set<int>fool1;
    fool1.insert(1);//普通插入
    //带暗示插入
    //pair<int,double>//等价于unordered_set<int,double>::value_type;
    fool1.insert(fool1.end(),2);
    unorderedSet(fool1,"插入元素后的foll1：");

    //插入一个范围
    unordered_set<int>fool2;
    fool2.insert(3);
    fool2.insert(4);
    fool2.insert(5);
    unorderedSet(fool1,"插入元素后的foll1：");
    fool1.insert(fool2.begin(),fool2.end());
    unorderedSet(fool1,"插入元素后的foll1：");

    unordered_set<int>::iterator it;
    //查找主键4
    it=fool1.find(4);
    if(it!=fool1.end())
    {
        cout<<"fool1.find(4):"<<*it<<endl;
    }

    //删除上述找到的元素
    if(it!=fool1.end())
    {
        fool1.erase(it);
    }
    unorderedSet(fool1,"删除主键为4的元素后的fool1：");

    //遍历删除主键等于2，删除元素会使迭代范围发生变化
    if(*it==2)
    {
        fool1.erase(it);
        //break;
    }

    //内部数据为
    cout<<"buck_count:"<<fool1.bucket_count()<<endl;
    cout<<"max_bucket_count:"<<fool1.max_bucket_count()<<endl;
    cout<<"bucket_size:"<<fool1.bucket_size(0)<<endl;
    cout<<"load_factor:"<<fool1.load_factor()<<endl;
    cout<<"max_load_factor:"<<fool1.max_load_factor()<<endl;

    unorderedSet(fool1,"删除主键为2的元素后的fool1：");
    
    fool1.clear();
    unorderedSet(fool1,"清空后的fool1：");

}

int main()
{
    test0();
    return 0;
}

