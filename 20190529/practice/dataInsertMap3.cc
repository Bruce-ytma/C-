//
//map中数据的插入
//3.用数组的方式插入
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
    mapStudent[1]="student_one";
    mapStudent[2]="student_two";
    mapStudent[3]="student_three";

    map<int,string>::iterator it;
    for(it=mapStudent.begin();it!=mapStudent.end();++it)
    {
        cout<<it->first<<"-->"<<it->second<<endl;
    }
    return 0;
}

