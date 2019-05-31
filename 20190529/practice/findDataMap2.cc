//
//在map中查找数据
//
#include <iostream>
#include<map>
#include<string>
using std::cout;
using std::endl;
using std::map;
using std::pair;
using std::string;

int main()
{
    map<int,string>mapStudent;
    mapStudent[1]="student_one";
    mapStudent[2]="student_two";
    mapStudent[3]="student_three";
    map<int,string>::iterator it;
    it=mapStudent.lower_bound(1);//返回的是下界为1的迭代器
    cout<<it->second<<endl;
    it=mapStudent.lower_bound(2);//返回的是下界为2的迭代器
    cout<<it->second<<endl;
    it=mapStudent.lower_bound(3);//返回的是下界为3的迭代器
    cout<<it->second<<endl;
    
    it=mapStudent.lower_bound(3);//返回的是下界为3的迭代器
    cout<<it->second<<endl;
    it=mapStudent.lower_bound(2);//返回的是下界为2的迭代器
    cout<<it->second<<endl;

    pair<map<int,string>::iterator,map<int,string>::iterator>mappair;
    mappair=mapStudent.equal_range(2);
    if(mappair.first==mappair.second)
    {
        cout<<"Do not find"<<endl;
    }
    else
    {
        cout<<"Find"<<endl;
    }
    mappair=mapStudent.equal_range(3);
    if(mappair.first==mappair.second)
    {
        cout<<"Do not find"<<endl;
    }
    else
    {
        cout<<"Find"<<endl;
    }
    return 0;
}

