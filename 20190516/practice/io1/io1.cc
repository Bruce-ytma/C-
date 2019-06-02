///*************************************************************************
///     @FileName: io1.cc
///     @Author:   ytma
///     @Email:    1539447319@qq.com
///     @Time:   Sat 01 Jun 2019 10:00:11 PM CST
///*************************************************************************
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void printCinStatus()
{
    cout<<"cin's badbit="<<cin.bad()<<endl
        <<"cin's failbit="<<cin.fail()<<endl
        <<"cin's eofbit="<<cin.eof()<<endl
        <<"cin's goodbit="<<cin.good()<<endl;
}

void test0()
{
    printCinStatus();
    ifstream ifs("io1.cc");//定义并打开一个ifstream对象
    if(!ifs.good())
    {
        cout<<"Open file error."<<endl;
        return;
    }

    //cout<<"This is a new line."<<endl;
    //ofstream ofs("test.txt");
    //string line;
    //while(getline(ifs,line))
    //{
    //    ofs<<line<<endl;
    //}
    
    //string s;
    //while(ifs>>s)//打印输出到屏幕，遇到空格键就换行
    //{
    //    cout<<s<<endl;
    //}
    
    vector<string> str;
    string line;
    while(getline(ifs,line))//打印输出到屏幕，以行输出
    {
        //cout<<line<<endl;
        str.push_back(line);
    }

    vector<string>::iterator it;
    for(it=str.begin();it!=str.end();++it)
    {
        cout<<*it<<endl;
    }
    ifs.close();
}

void test1()
{
    ifstream ifs("io1.cc");
    if(!ifs.good())
    {
        cout<<"Open file error."<<endl;
        return;
    }
    ofstream ofs("test.txt");
    string line;
    while(getline(ifs,line))
    {
        ofs<<line<<endl;
    }
}

int main()
{
    //test0();
    test1();
    return 0;
}

