//
//map中数据的插入
//2.用insert函数插入value_type数据
//
#include <iostream>
#include<map>
#include<string>
using std::cout;
using std::endl;
using std::map;
using std::string;

int main()
{
    map<int,string>mapStudent;
    mapStudent.insert(map<int,string>::value_type(1,"student_one"));
    mapStudent.insert(map<int,string>::value_type(2,"student_two"));
    mapStudent.insert(map<int,string>::value_type(3,"student_three"));

    map<int,string>::iterator it;
    for(it=mapStudent.begin();it!=mapStudent.end();++it)
    {
        cout<<it->first<<"-->"<<it->second<<endl;
    }
    return 0;
}

