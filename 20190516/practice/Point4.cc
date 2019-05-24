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
    explicit//_implcit
    Point(int ix,int iy)//如果写成Point(int ix=0,int iy=0),就不需要Point()
    :_ix(ix),_iy(iy)//c++中的初始化表达式(列表)   (初始化)
    {
        //_ix=ix;//赋值语句，不是初始化
        //_iy=iy;
        cout<<"Point(int=0,int=0)"<<endl;
    }

//#if 0
//    //如果不写，系统会自动提供复制构造函数
//    Point(const Point &rhs)//复制（拷贝）构造函数
//        :_ix(rhs._ix)
//         ,_iy(rhs._iy)
//    {
//        cout<<"Point(const Point &)"<<endl;
//    }
//#endif
//
//    Point &operator =(const Point &rhs)
//    {
//        _ix=rhs._ix;
//        _iy=rhs._iy;
//        cout<<"Point &operator =(const Point &rhs)"<<endl;
//    }

    void print()
    {
        cout<<"("<<_ix<<","<<_iy<<")";
    }

    //析构函数只有一个
    ~Point()//作用：执行清理操作
    {
        cout<<"~Point()"<<endl;
    }

private:
    //const成员只能在初始化列表进行初始化
    int _ix;
    int _iy;
};

class Line
{
public:
    Line(int x1,int y1,int x2,int y2)
    :_pt1(x1,y1)
    ,_pt2(x2,y2)
    {
        cout<<"Line(int,int,int,int)"<<endl;
    }

    void printLine()
    {
        _pt1.print();
        cout<<"-->";
        _pt2.print();
    }
private:
    //一般情况下，对于子对象成员而言，其构造都要放在
    //其整体类的构造函数初始化列表中进行初始化
    //
    //组合设计模式
    //
    Point _pt1;
    Point _pt2;
};

int main()
{
    Line Line(1,2,3,4);
    Line.printLine();
    return 0;
}

