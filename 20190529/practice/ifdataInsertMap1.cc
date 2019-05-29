//
//通过pair判断插入函数是否成功
//
#include <iostream>
#include<map>
#include<string>
using std::cout;
using std::endl;
using std::string;
using std::map;
using std::pair;

int main()
{
    map<int,string>mapStudent;
    pair<map<int,string>::iterator,bool>Insert_pair;
    Insert_pair=mapStudent.insert(pair<int,string>(1,"student_one"));
    if(Insert_pair.second==true)
    {
        cout<<"Insert successfully"<<endl;        
    }
    else
    {
        cout<<"Insert failure"<<endl;
    }
    Insert_pair=mapStudent.insert(pair<int,string>(1,"student_two"));
    if(Insert_pair.second==true)
    {
        cout<<"Insert successfully"<<endl;
    }
    else
    {
        cout<<"Insert failure"<<endl;
    }
    Insert_pair=mapStudent.insert(pair<int,string>(2,"student_two"));
    if(Insert_pair.second==true)
    {
        cout<<"Insert successfully"<<endl;
    }
    else
    {
        cout<<"Insert failure"<<endl;
    }

    map<int,string>::iterator it;
    for(it=mapStudent.begin();it!=mapStudent.end();++it)
    {
        cout<<it->first<<"-->"<<it->second<<endl;
    }
    return 0;
}

