///*************************************************************************
///     @FileName: string2.cc
///     @Author:   ytma
///     @Email:    1539447319@qq.com
///     @Time:   Tue 04 Jun 2019 03:22:25 PM CST
///*************************************************************************
#include <string.h>
#include <iostream>
using namespace std;

class Someclass
{
public:
    //如果手动提供了析构函数，复制构造函数，赋值运算符函数，
    //编译器不自动提供移动构造函数和移动赋值运算符函数
    //如果手动提供了移动构造函数或移动赋值运算符函数，编译器
    //不会自动提供复制构造函数和赋值运算符函数
    Someclass()//构造函数
    {
        cout<<"Someclass()"<<endl;
    }
    
    Someclass(const char *s)//有参构造函数
        :_s(new char[strlen(s)+1]())
    {
        cout<<"Someclass(const char *)"<<endl;
    }

    Someclass(const Someclass & sc)//复制构造函数
        :_s(new char[strlen(sc._s)+1]())
    {
        cout<<"Someclass(const Someclass &)"<<endl;
        strcpy(_s,sc._s);
    }

    Someclass(Someclass && sc)//移动构造函数
    {
        cout<<"Someclass(Someclass &&)"<<endl;
        _s=sc._s;
        sc._s=nullptr;
    }

    Someclass &operator=(const Someclass &sc)//赋值运算符函数
    {
        cout<<"Some &operator=(const Someclass &)"<<endl;
        if(this==&sc)
        {
            return *this;
        }
        if(_s)
        {
            free(_s);
            _s=nullptr;
        }
        _s=(char *)malloc(sizeof(char)*(strlen(sc._s)+1));
        strcpy(_s,sc._s);
        return *this;
    }

    Someclass &operator=(Someclass &&sc)//移动赋值运算符函数
    {
        cout<<"Someclass &operator=(Someclass &&)"<<endl;
        if(this==&sc)
        {
            return *this;
        }
        if(_s)
        {
            free(_s);
            _s=nullptr;
        }
        _s=sc._s;
        sc._s=nullptr;
        return *this;
    }

    ~Someclass()
    {
        cout<<"~Someclass()"<<endl;
        if(_s)
        {
            free(_s);
        }
    }

    void print()const
    {
        cout<<"print()"<<endl;
        if(!_s)
        {
            return;
        }
        cout<<"s="<<_s<<endl;
    }
private:
    char *_s;
};

int main()
{
    Someclass sc="abc";//隐式调用构造函数
    Someclass sc2("xxx");
    sc2=std::move(sc);//强制调用移动赋值构造函数
    sc.print();//输出s=
    sc2.print();
    return 0;
}

