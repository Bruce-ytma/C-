/*************************************************************************
  @FileName: set.cc
  @Author:   ytma
  @Email:    1539447319@qq.com
  @Time:   Thu 30 May 2019 08:19:21 PM CST
 ************************************************************************/
#include <iostream>
#include <set>
using namespace std;

void test0()
{
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(1);//set中不能存放关键字相同的元素
    cout<<"size="<<s.size()<<endl;
    cout<<"maxsize="<<s.max_size()<<endl;
    //cout<<"set中的第一个元素是："<<s.begin()<<endl;
    //cout<<"set中的最后一个元素是："<<s.end()<<endl;
    s.clear();
    if(s.empty())
    {
        cout<<"set为空。"<<endl;
    }
    cout<<"size="<<s.size()<<endl;
    cout<<"maxsize="<<s.max_size()<<endl;
}

void test1()
{
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(1);//set中不能存放关键字相同的元素
    cout<<"set中出现的1的次数为："<<s.count(1)<<endl;
    cout<<"set中出现的4的次数为："<<s.count(4)<<endl;
}

void test2()
{
    set<int>s;
    set<int>::iterator it;
    for(int i=1;i<=5;i++)
    {
        s.insert(i);
    }
    for(it=s.begin();it!=s.end();++it)
    {
        cout<<*it<<" ";
    }
    cout<<endl;

    pair<set<int>::const_iterator,set<int>::const_iterator>pr;
    pr=s.equal_range(3);//返回一对定位器，分别表示第一个大于或者等于
                        //给定关键值的元素和第一个大于给定关键值的元素
    cout<<"第一个大于等于3的数是："<<*pr.first<<endl;
    cout<<"第一个大于3的数是："<<*pr.second<<endl;
}

void test3()
{
    set<int>s;
    set<int>::const_iterator it;
    set<int>::iterator first;
    set<int>::iterator second;
    for(int i=1;i<=10;i++)
    {
        s.insert(i);
    }
    
    //erase(iterator)  ,删除定位器iterator指向的值
    //erase(first,second),删除定位器first和second之间的值
    //erase(key_value),删除键值key_value的值
    s.erase(s.begin());//删除iterator指向的第一个值
    cout<<"第一次删除后set中的元素为：";
    for(it=s.begin();it!=s.end();++it)
    {
        cout<<*it<<" ";
    }
    cout<<endl;

    first=s.begin();//第二种删除方法
    second=s.begin();
    second++;
    second++;
    s.erase(first,second);
    cout<<"第二次删除后set中的元素为：";
    for(it=s.begin();it!=s.end();++it)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    
    s.erase(8);//第三种删除
    cout<<"删除后set中的元素为：";
    for(it=s.begin();it!=s.end();++it)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}

void test4()
{
    int a[]={1,2,3};
    set<int>s(a,a+3);
    set<int>::iterator it;
    if((it=s.find(2))!=s.end())//find()返回给定值的定位器，如果没找到则返回end()
    {
        cout<<*it<<endl;
    }
}

void test5()
{
    int a[]={1,2,3};
    set<int>s(a,a+3);
    set<int>::iterator it;
    
    //1.insert(key_value),将Key_value插入到set中，返回值是pair<set<int>::iterator,bool>
    //bool标志着插入是否成功，iterator代表插入的位置，若key_value已在set中，则iterator
    //表示key_value在set中的位置
    //2.insert(first,second),将定位器first到second之间的元素插入到set中，返回值是void
    s.insert(a,a+3);
    for(it=s.begin();it!=s.end();++it)
    {
        cout<<*it<<" ";
    }
    cout<<endl;

    //pair<set<int>::iterator,bool> pr;
    auto pr=s.insert(5);
    if(pr.second)
    {
        cout<<*pr.first<<endl;
    }
}

void test6()
{
    set<int>s;
    s.insert(1);
    s.insert(3);
    s.insert(4);
    
    //lower_bound(key_value)返回第一个大于等于key_value的定位器
    //upper_bound(key_value)返回最后一个大于等于key_value的定位器
    cout<<*s.lower_bound(2)<<endl;
    cout<<*s.lower_bound(3)<<endl;
    cout<<*s.upper_bound(3)<<endl;
}

int main()
{
    //test0();
    //test1();
    //test2();
    //test3();
    //test4();
    //test5();
    test6();
    return 0;
}

