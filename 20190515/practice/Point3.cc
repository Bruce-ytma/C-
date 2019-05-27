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

#if 0
    //如果不写，系统会自动提供复制构造函数
    Point(const Point &rhs)//复制（拷贝）构造函数
        :_ix(rhs._ix)
         ,_iy(rhs._iy)
    {
        cout<<"Point(const Point &)"<<endl;
    }
#endif

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

int test0()
{
    int a=3;
    int b=a;
    cout<<"a="<<a<<endl
        <<"b="<<b<<endl;
    
    Point pt(1,2);
    cout<<"pt=";
    pt.print();
    
    Point pt2=pt;
    cout<<"pt2=";
    pt2.print();
    return 0;
}

int main()
{
    test0();
    return 0;
}
