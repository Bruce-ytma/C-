//
//map中数据的插入
//1.用insert函数插入pair数据
#include <iostream>
#include<map>
#include<string>
using std::cout;
using std::endl;
using std::map;
using std::string;
using std::pair;

int main()
{
    map<int,string> mapStudent;
    mapStudent.insert(pair<int,string>(1,"student_one"));
    mapStudent.insert(pair<int,string>(2,"student_two"));
    mapStudent.insert(pair<int,string>(3,"student_three"));
    map<int,string>::iterator it;
    for(it=mapStudent.begin();it!=mapStudent.end();++it)
    {
        cout<<it->first<<"-->"<<it->second<<endl;
    }
    return 0;
}

