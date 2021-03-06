//
//模板形式的单例类
//
#include<string.h>
#include <iostream>
using std::cout;
using std::endl;
using std::string;


template<typename Type>
class CSingleton
{
private:
    CSingleton()
    {
        cout<<"CSingleton()"<<endl;
    }

    static Type *_pInstance;
public:
    template<typename... Args>//可变参数
    static Type *getInstance(Args... args)
    {
        if(_pInstance==nullptr)
        {
            _pInstance=new Type(args...);
        }
        return _pInstance;
    }
};

template<typename Type>
Type *CSingleton<Type>::_pInstance=nullptr;

class Point
{
public:
    Point(int x,int y)
        :_x(x)
        ,_y(y)
    {
        cout<<"Point()"<<endl;
    }

    void print()
    {
        cout<<"("<<_x<<","
            <<_y<<")"<<endl;
    }
    ~Point()
    {
        cout<<"~Point()"<<endl;
    }
private:
    int _x;
    int _y;
};

class Computer
{
public:
    Computer(string brand,double price)
        :_brand(brand)
        ,_price(price)
    {
        cout<<"Computer(string,double)"<<endl;
    }

    void print()
    {
        cout<<"brand:"<<_brand<<endl
            <<"price:"<<_price<<endl;
    }

    ~Computer()
    {
        cout<<"~Computer()"<<endl;
    }
private:
    string _brand;
    double _price;
};

int main()
{
    Computer *p1=CSingleton<Computer>::getInstance("Xiaomi",6666);
    p1->print();
    //printf("p1=%p\n",p1);
    Computer *p2=CSingleton<Computer>::getInstance("Xiaomi",6666);
    p2->print();
    //printf("p2=%p\n",p2);
    Point *p3=CSingleton<Point>::getInstance(1,2);
    p3->print();
    //printf("p3=%p\n",p3);
    Point *p4=CSingleton<Point>::getInstance(1,2);
    p4->print();
    //printf("p4=%p\n",p4);
    return 0;
}

