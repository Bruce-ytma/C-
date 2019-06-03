///*************************************************************************
///     @FileName: string.cc
///     @Author:   ytma
///     @Email:    1539447319@qq.com
///     @Time:   Mon 03 Jun 2019 10:17:15 PM CST
///*************************************************************************
#include <string.h>
#include <iostream>
#include <vector>
using namespace std;

class String
{
public:
    String(const char *pstr)
    {
        cout<<"String(const char *)"<<endl;
        //strcpy(_pstr,pstr);
    }

    //复制构造函数
    String(const String &rhs)
        :_pstr(new char[strlen(rhs._pstr)+1]())
    {
        strcpy(_pstr,rhs._pstr);
        cout<<"String(const String &)"<<endl;
    }

    //赋值运算符函数
    String &operator=(const String &rhs)
    {
        cout<<"String &operator(const String &)"<<endl;
        if(this!=&rhs)
        {
            delete []_pstr;
            _pstr=new char[strlen(rhs._pstr)+1]();
            strcpy(_pstr,rhs._pstr);
        }
        return *this;
    }

    //移动构造函数和移动赋值运算符统称为具有移动语义的函数
    //复制构造函数和赋值运算符统称为具有复制控制语义的函数
    //
    //具有移动语义的函数要优先于控制语义的函数
    
#if 0
    //移动构造函数
    String(String &&rhs)//rhs本身是一个左值
        :_pstr(rhs._pstr)//浅拷贝
    {
        cout<<"String(String &&rhs)"<<endl;
        rhs._pstr=nullptr;
    }

    //移动赋值运算符函数
    String &operator=(String &&rhs)
    {
        cout<<"String &operator=(String &&rhs)"<<endl;
        if(this!=&rhs)
        {
            delete []_pstr;
            _pstr=rhs._pstr;
            rhs._pstr=nullptr;
        }
        return *this;
    }
#endif

    ~String()
    {
        if(_pstr)
        {
            delete []_pstr;
        }
        cout<<"~String()"<<endl;
    }

    friend std::ostream & operator<<(std::ostream &os,const String &rhs);

private:
    char *_pstr;
};

std::ostream &operator<<(std::ostream &os,const String &rhs)
{
    os<<rhs._pstr;
    return os;
}

void test0()
{
    vector<String> strs;
    strs.push_back("hello,world");
    cout<<"........"<<endl;

    String str1="wangdao";
    cout<<"str1="<<str1<<endl;
    cout<<endl;
    //strs.push_back(str1);//只要放在容器中的元素，都是一个全新的副本(copy)
    strs.push_back(std::move(str1));

    String str2("shenzhen");
    str2="henggang";
    cout<<"str2="<<str2<<endl;
    cout<<endl;

    cout<<"test std::move"<<endl;
    //std::move显示将一个左值转换成一个右值，本质上就是一个强制转换
    str2=std::move(str1);//该语句之后，就不在使用str1对象了
    cout<<"str2="<<str2<<endl;

    //str2=std::move(str2);
    cout<<"......."<<endl;
}

String s1("hello");//全局对象

String getString()
{
    //String str("hello");//局部对象
    //return str;//当返回的对象为局部对象时，如果定义了
                 //移动构造函数，return时调用的是移动构造函数
    
    return s1;//当返回的对象是全局对象时，return调用的是赋值构造函数
}

void test1()
{
    int a=1,b=2;
    cout<<"a="<<a<<",b="<<b<<endl;
    b=std::move(a);//对于内置类型的数据，表现得不明显
    cout<<"a="<<a<<",b="<<b<<endl;

    getString();
}

int main()
{
    //test0();
    test1();
    return 0;
}

