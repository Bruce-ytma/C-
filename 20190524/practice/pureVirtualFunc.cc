//
//纯虚函数
//
#include <iostream>
using namespace std;

class Shape//抽象基类
{
public:
    virtual float area()const//虚函数
    {
        return 0.0;
    }

    virtual float volume()const//虚函数
    {
        return 0.0;
    }

    virtual void shapeName()const=0;//纯虚函数
};

class Point:public Shape
{
public:
    Point(float x=0,float y=0);
    void setPoint(float,float);
    float getX()const
    {
        return _x;
    }
    float getY()const
    {
        return _y;
    }

    virtual void shapeName()const//对虚函数进行再定义
    {
        cout<<"Point::shapeName()"<<endl;
    }

    friend ostream &operator <<(ostream &,const Point &);
protected:
    float _x;
    float _y;
};

Point::Point(float x,float y)
{
    _x=x;
    _y=y;
}

void Point::setPoint(float x,float y)
{
    _x=x;
    _y=y;
}

ostream & operator <<(ostream &output,const Point &p)
{
    output<<"["<<p._x<<","<<p._y<<"]";
    return output;
}

class Circle:public Point
{
public:
    Circle(float x=0,float y=0,float r=0);
    void setRadius(float);
    float getRadius()const;
    virtual float area()const;
    virtual void shapeName()const//对虚函数进行再定义
    {
        cout<<"Circle::shapeName()"<<endl;
    }

    friend ostream &operator <<(ostream &,const Circle &);
protected:
    float _radius;
};

Circle::Circle(float x,float y,float r)
    :Point(x,y)
    ,_radius(r)
{
    cout<<"Circle(float,float,float)"<<endl;
}

void Circle::setRadius(float r)
{
    _radius=r;
    cout<<"Circle::setRadius(float)"<<endl;   
}

float Circle::getRadius()const
{
    cout<<"Circle::getRadius()"<<endl;
    return _radius;
}

float Circle::area()const
{
    cout<<"Circle::area()"<<endl;
    return 3.14159*_radius*_radius;
}

ostream &operator <<(ostream &output,const Circle &c)
{
    output<<"["<<c._x<<","<<c._y<<"],r="<<c._radius<<endl;
    return output;
}

class Cylinder:public Circle
{
public:
    Cylinder(float _x=0,float _y=0,float r=0,float h=0);
    void setHeight(float);
    virtual float area()const;
    virtual float volume()const;
    virtual void shapeName()const//对虚函数进行再定义
    {
        cout<<"Cylinder::shapeName()"<<endl;
    }

    friend ostream &operator <<(ostream &,const Cylinder &);
protected:
    float _height;
};

Cylinder::Cylinder(float x,float y,float r,float h)
    :Circle(x,y,r)
    ,_height(h)
{
    cout<<"Cylinder(float,float,float)"<<endl;
}

void Cylinder::setHeight(float h)
{
    _height=h;
    cout<<"Cylinder::setHeight(float)"<<endl;
}

float Cylinder::area()const
{
    cout<<"Cylinder::area()"<<endl;
    return 2*Circle::area()+2*3.14159*_radius*_height;
}

float Cylinder::volume()const
{
    cout<<"Cylinder::volume()"<<endl;
    return Circle::area()*_height;
}

ostream &operator <<(ostream &output,const Cylinder &cy)
{
    output<<"["<<cy._x<<","<<cy._y<<"],r="
        <<cy._radius<<",h="<<cy._height;
    return output;
}

int main()
{
    Point point(3.2,4.5);//建立Point类对象point
    Circle circle(2.4,1.2,5.6);//建立Circle类对象circle
    Cylinder cylinder(3.5,6.4,5.2,10.5);//建立Cylinder类对象cylinder
    point.shapeName();//静态关联
    cout<<point<<endl;
    circle.shapeName();//静态关联
    cout<<circle<<endl;
    cylinder.shapeName();//静态关联
    cout<<cylinder<<endl;

    Shape *pt;//定义基类指针
    pt=&point;//指针指向Point类对象
    pt->shapeName();//动态关联
    cout<<"x="<<point.getX()<<",y="<<point.getY()<<endl<<"area="
        <<pt->area()<<endl<<"volume="<<pt->volume()<<endl<<endl;
    pt=&circle;//指针指向Circle类对象
    pt->shapeName();//动态关联
    cout<<"x="<<circle.getX()<<",y="<<circle.getY()<<endl<<"area="
        <<pt->area()<<endl<<"volume="<<pt->volume()<<endl<<endl;
    pt=&cylinder;//指针指向Cylinder类对象
    pt->shapeName();//动态关联
    cout<<"x="<<cylinder.getX()<<",y="<<cylinder.getY()<<endl<<"area="
        <<pt->area()<<endl<<"volume="<<pt->volume()<<endl<<endl;
    return 0;
}

