/*************************************************************************
  @FileName: io2.cc
  @Author:   ytma
  @Email:    1539447319@qq.com
  @Time:   Sat 01 Jun 2019 04:13:18 PM CST
 ************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

vector<string> file;
void test0()
{
    ifstream ifs;
    ifs.open("io2.cc");
    if(!ifs.good())
    {
        cout<<"Open file error."<<endl;
        return;
    }

    //string word;
    //while(ifs>>word)
    string line;
    while(std::getline(ifs,line))
    {
        cout<<line<<endl;
        file.push_back(line);
    }

    ifs.close();
}

void test1()
{
    test0();
    ofstream ofs("test.txt");
    if(!ofs)
    {
        cout<<"Ofstream open file error."<<endl;
        return;
    }

    for(auto &line:file)
    {
        ofs<<line<<endl;
    }
    ofs.close();
}

int main()
{
    //test0();
    test1();
    return 0;
}

