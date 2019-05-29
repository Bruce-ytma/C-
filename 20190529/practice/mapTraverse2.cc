//
//用数组的形式遍历map
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

    int size=mapStudent.size();
    //for(int idx=0;idx<size;++idx)
    for(int idx=1;idx<=size;++idx)
    {
        cout<<mapStudent[idx]<<endl;
    }
    return 0;
}

