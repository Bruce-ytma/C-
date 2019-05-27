//
//静态联编
//
#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
    Point(double x,double y)
    {
        _x=x;
        _y=y;
    }

    double Area()const//定义的常成员函数
    {
        return 0.0;
    }
private:
    double _x;
    double _y;
};

class Rectangle:public Point
{
public:
    Rectangle(double x,double y,double w,double h);//声明派生类的构造函数
    double Area()const
    {
        return _w*_h;
    }
private:
    double _w;
    double _h;
};

Rectangle::Rectangle(double x,double y,double w,double h)//派生类构造函数的实现
    :Point(x,y)
{
    _w=w;
    _h=h;
}

void fun(Point &s)
{
    cout<<s.Area()<<endl;
}

int main()
{
    Rectangle rec(3.5,15.2,5.0,28.0);
    fun(rec);//调用函数fun()
    return 0;
}

