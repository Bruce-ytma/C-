//
//利用反向迭代器，遍历map
//
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
    map<int,string>mapStudent;
    mapStudent.insert(pair<int,string>(1,"student_one"));
    mapStudent.insert(pair<int,string>(2,"student_two"));
    mapStudent.insert(pair<int,string>(3,"student_three"));
    map<int,string>::reverse_iterator it;
    for(it=mapStudent.rbegin();it!=mapStudent.rend();++it)
    {
        cout<<it->first<<"-->"<<it->second<<endl;
    }
    return 0;
}

