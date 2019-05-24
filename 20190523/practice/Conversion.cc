//
//基类与派生类之间的转换
//
#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
    Base(int ix,int iy)
        :_ix(ix)
        ,_iy(iy)
    {
        cout<<"Base(int,int)"<<endl;
    }

    void display();
private:
    int _ix;
    int _iy;
};

void Base::display()
{
    cout<<"ix="<<_ix<<endl
        <<"iy="<<_iy<<endl;
}

class Derived:public Base
{
public:
    Derived(int ix,int iy,int iz)
        :Base(ix,iy)
        ,_iz(iz)
    {
        cout<<"Derived(int,int,int)"<<endl;
    }

    void display();
private:
    int _iz;
};

void Derived::display()
{
    Base::display();
    cout<<"iz="<<_iz<<endl;
}

void print1(Base &pb)
{
    pb.display();
}

void print2(Derived &pd)
{
    pd.display();
}

void print3(Base b)
{
    b.display();
}

void print4(Derived d)
{
    d.display();
}

int main()
{
    Base b(3,4);
    b.display();
    Derived d(10,20,30);
    d.display();

    Base *pb;
    Derived *pd;
    pb=&b;
    pb->display();//输出结果：3 4

    //pd=&b;//error 派生类指针不能指向基类对象
    //pd->display();//error 会产生段错误
    
    pd=&d;
    pd->display();//输出结果：10 20 30

    pb=&d;
    pb->display();//输出结果：10  20

    print1(d);//输出结果：10 20
    //print2(b);//error 不能用基类对象给派生类引用赋值
    print3(d);//输出结果：10 20
    //print4(b);//error 不能用基类对象给派生类对象赋值
    
    //pd=pb;//error 不能用基类指针给派生类指针赋值
    
    pd=(Derived *)pb;//可以强制转换，但是不安全
    pb->display();//输出结果：10 20
    return 0;
}

