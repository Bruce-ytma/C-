//
//函数模板
//
#include <iostream>
using std::cout;
using std::endl;

template<typename T>void swap(T *a,T *b)
{
    T temp=*a;
    *a=*b;
    *b=temp;
}

int main()
{
    int n1=100,n2=200;//交换两个int型变量的值
    cout<<"n1="<<n1<<endl
        <<"n2="<<n2<<endl;
    swap(&n1,&n2);
    cout<<"n1="<<n1<<endl
        <<"n2="<<n2<<endl;

    float f1=12.5,f2=56.93;
    cout<<"f1="<<f1<<endl
        <<"f2="<<f2<<endl;
    swap(&f1,&f2);
    cout<<"f1="<<f1<<endl
        <<"f2="<<f2<<endl;

    char c1='A',c2='B';
    cout<<"c1="<<c1<<endl
        <<"c2="<<c2<<endl;
    swap(&c1,&c2);
    cout<<"c1="<<c1<<endl
        <<"c2="<<c2<<endl;

    bool b1=false,b2=true;
    cout<<"b1="<<b1<<endl
        <<"b2="<<b2<<endl;
    swap(&b1,&b2);
    cout<<"b1="<<b1<<endl
        <<"b2="<<b2<<endl;
    return 0;
}

