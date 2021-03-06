///*************************************************************************
///     @FileName: auto_ptr.cc
///     @Author:   ytma
///     @Email:    1539447319@qq.com
///     @Time:   Tue 04 Jun 2019 02:49:12 PM CST
///*************************************************************************
#include <iostream>
#include <memory>
using namespace std;

class Point
{
public:
    Point(int ix=0,int iy=0)
        :_ix(ix)
        ,_iy(iy)
    {
        cout<<"Point(int,int)"<<endl;
    }

    void print()const
    {
        cout<<"("<<_ix<<","<<_iy<<")"<<endl;
    }

    ~Point()
    {
        cout<<"~Point()"<<endl;
    }
private:
    int _ix;
    int _iy;
};

int main()
{
    Point *pt=new Point(1,2);
    auto_ptr<Point> ap(pt);
    //cout<<"ap's get="<<ap.get()<<endl;
    //cout<<"pt="<<pt<<endl;
    
    //ap->print();
    //(*ap).print();

    auto_ptr<Point> ap2(ap);//在语法形式上是复制语义
                            //但在底层已经完成了所有权的转移
                            //存在缺陷，目前不使用了
    cout<<"ap2->";
    ap2->print();
    (*ap2).print();
    
    //cout<<endl<<"ap->";
    //ap->print();
    //(*ap).print();

    //cout<<"......"<<endl;
    return 0;
}

