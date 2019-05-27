#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
    //在未显示定义构造函数时，系统会自动提供一个默认构造函数
    //如果有显示自定义有参构造函数，此时系统就不会在自动提供默认构造函数
    //需要显示提供默认构造函数
    //
    //构造函数支持函数重载
    Point();
    Point(int ix,int iy)//如果写成Point(int ix=0,int iy=0),就不需要Point()
    :_ix(ix),_iy(iy)//c++中的初始化表达式(列表)
    {
        //_ix=ix;
        //_iy=iy;
        cout<<"Point(int=0,int=0)"<<endl;
    }

    void print()
    {
        cout<<"("<<_ix<<","<<_iy<<")"<<endl;
    }

    //析构函数只有一个
    ~Point()//作用：执行清理操作
    {
        cout<<"~Point()"<<endl;
    }

private:
    int _ix;
    int _iy;
};

class X
{
    
};

class Foo
{
public:
    //数据成员的初始化与其在初始化列表中的顺序无关，
    //只与其在被声明时的顺序有关
    Foo(int number)
        :_iy(number),_ix(_iy)
    {
        cout<<"Foo(int)"<<endl;
    }
    
    void print()
    {
        cout<<"("<<_ix<<","<<_iy<<")"<<endl;
    }
private:
    int _ix;
    int _iy;
};

int test0()
{
    int number(10);
    Point pt(1,2);
    cout<<"number="<<number<<endl;
    pt.print();
    return 0;
}

int test1()
{
    Foo foo(10);
    foo.print();
    return 0;
}

void test2()
{
    X x;
    cout<<"test2()"<<endl;
}

int main()
{
    //test0();
    //test1();
    test2();
    return 0;
}
