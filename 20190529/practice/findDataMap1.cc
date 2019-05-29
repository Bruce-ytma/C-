//
//用find函数来定位数据在map中出现的位置
//
#include <iostream>
#include<map>
#include<string>
using std::cout;
using std::endl;
using std::string;
using std::pair;
using std::map;

int main()
{
    map<int,string>mapStudent;
    mapStudent.insert(pair<int,string>(1,"student_one"));
    mapStudent.insert(pair<int,string>(2,"student_two"));
    mapStudent.insert(pair<int,string>(3,"student_three"));
    map<int,string>::iterator it;
    it=mapStudent.find(1);
    if(it!=mapStudent.end())
    {
        cout<<"Find,the value is:"<<it->second<<endl;
    }
    else
    {
        cout<<"Do not find."<<endl;
    }
    return 0;
}

