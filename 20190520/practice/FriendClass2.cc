///*************************************************************************
///     @FileName: FriendFunc2.cc
///     @Author:   ytma
///     @Email:    1539447319@qq.com
///     @Time:     2019-06-07 10:49:59
///*************************************************************************
#include <iostream>
#include <cmath>
using namespace std;

class Line;//声明类Line
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
    friend class Line;//友元类的声明，位置不受限制
};

class Line //类Line的定义，其中所有的函数都是Point类的友元函数
{
public:
    float display(Point &p1,Point &p2)//可访问p1和p2的私有成员
    {
        float d;
        d=sqrt((p1._x-p2._x)*(p1._x-p2._x)+(p1._y-p2._y)*(p1._y-p2._y));
        return d;
    }

    void set(Point *p1,int a,int b)//可访问p1和p2的私有成员
    {
        p1->_x=a;
        p1->_y=b;
    }
};

int main()
{
    Line cz1;//声明一个Line类的对象cz1
    Point p1(1,2),p2(4,5);//声明两个Point类的对象p1和p2
    p1.display();
    cout<<"与";
    p2.display();

    cout<<"距离="<<cz1.display(p1,p2)<<endl;

    cz1.set(&p1,3,4);//调用cz1的成员函数set()改写p1中的私有成员x和y
    p1.display();
    cout<<endl;
    return 0;
}

