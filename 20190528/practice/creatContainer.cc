//
//容器的创建与元素的访问
//
#include <iostream>
#include<vector>
#include<list>
#include<deque>
using std::cout;
using std::endl;
using std::vector;
using std::list;
using std::deque;

int main()
{
    vector<int> obV;//创建一个空的vector容器
    //size()用以返回元素的个数
    cout<<"obV的元素个数为："<<obV.size()<<endl<<endl;

    double sz[5]={1,2,3,4,5};
    deque<double> obD(sz,sz+5);//创建deque型容器，并用sz的首地址和末地址为其初始化
    //使用下标[]访问deque容器的元素
    for(size_t i=0;i<obD.size();i++)
    {
        cout<<obD[i]<<" ";
    }
    cout<<endl;

    list<float> obL(3,5);//创建一个大小为3的list型容器，其中每个元素都被初始化为5
    //obL[0]=3;//error List不支持下标访问
    //使用迭代器访问list容器的元素
    list<float>::iterator it=obL.begin();//
    while(it!=obL.end())
    {
        (*it)+=2;
        cout<<(*it)<<" ";
        it++;
    }
    cout<<endl;
    return 0;
}

