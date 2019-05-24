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
    {
        _ix=ix;
        _iy=iy;
    }

    void print()
    {
        cout<<"("<<_ix<<","<<_iy<<")"<<endl;
    }

private:
    int _ix;
    int _iy;
};

Point::Point()
{
    _ix=0;
    _iy=0;
}

int main()
{
    int number;
    Point pt0;//也有默认构造函数的调用
    pt0.print();
    Point pt(1,2);
    pt.print();
    return 0;
}

