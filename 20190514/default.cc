#include <iostream>
using std::cout;
using std::endl;

//缺省参数
int add(int x,int y=0)
{
    return x+y;
}

int add(int x,int y,int z)
{
    return x+y+z;
}

int main()
{
    int a=3,b=4,c=5;
    cout<<"add(a,b)="<<add(a,b)<<endl
        <<"add(a)="<<add(a)<<endl;
    return 0;
}
