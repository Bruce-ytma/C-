//
//类模板
//
#include <iostream>
using std::cout;
using std::endl;

template<typename T1,typename T2>
class Point
{
public:
    Point(T1 x,T2 y)
        :_x(x)
        ,_y(y)
    {
        cout<<"Point(T1,T2)"<<endl;
    }

    T1 getX()const;//获取x坐标
    void setX(T1 x);//设置x坐标
    T2 getY()const;//获取y坐标
    void setY(T2 y);//设置y坐标
private:
    T1 _x;
    T2 _y;
};

//除了 template 关键字后面要指明类型参数，类名 Point 后面
//也要带上类型参数，只是不加 typename 关键字了。另外需要注
//意的是，在类外定义成员函数时，template 后面的类型参数要
//和类声明时的一致。
template<typename T1,typename T2>//模板头
T1 Point<T1,T2>::getX()const//函数头
{
    return _x;
}

template<typename T1,typename T2>
void Point<T1,T2>::setX(T1 x)
{
    cout<<"Point<T1,T2>::setX(T1)"<<endl;
    _x=x;
}

template<typename T1,typename T2>//模板头
T2 Point<T1,T2>::getY()const//函数头
{
    return _y;
}

template<typename T1,typename T2>
void Point<T1,T2>::setY(T2 y)
{
    cout<<"Point<T1,T2>::setY(T2)"<<endl;
    _y=y;
}

int main()
{
    Point<int,int> p1(10,20);
    cout<<"x="<<p1.getX()<<",y="<<p1.getY()<<endl;
    
    Point<int,char *> p2(10,"东经180度");
    cout<<"x="<<p2.getX()<<",y="<<p2.getY()<<endl;
    
    Point<char *,char *> *p3=new Point<char *,char *>("东经180度","北纬210度");
    cout<<"x="<<p3->getX()<<",y="<<p3->getY()<<endl;
    return 0;
}

