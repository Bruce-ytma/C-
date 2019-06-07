///*************************************************************************
///     @FileName: FriendFunc2.cc
///     @Author:   ytma
///     @Email:    1539447319@qq.com
///     @Time:     2019-06-07 10:49:59
///*************************************************************************
#include <iostream>
#include <cmath>
using namespace std;

class Point
{
public:
    Point(int i,int j)
        :_x(i)
        ,_y(j)
    {
        cout<<"Point(int,int)"<<endl;
    }

    void display()
    {
        cout<<"("<<_x<<","<<_y<<")"<<endl;
    }
private:
    int _x;
    int _y;
    friend float display(Point &p1,Point &p2);//友元函数的声明，声明位置没有关系，可以是pubic，也可以是private
};

float display(Point &p1,Point &p2)
{
    //友元函数中可以访问类的private成员
    float d=sqrt((p1._x-p2._x)*(p1._x-p2._x)+(p1._y-p2._y)*(p1._y-p2._y));
    return d;
}

int main()
{
    Point p1(1,2),p2(4,5);//声明两个Point类的对象p1和p2
    p1.display();
    cout<<"与";
    p2.display();

    cout<<"距离="<<display(p1,p2)<<endl;
    return 0;
}

