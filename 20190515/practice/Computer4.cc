//
//析构函数与构造函数
//
#include<string.h>
#include <iostream>
using std::cout;
using std::endl;

class Computer
{
public:
    //在类内部实现的函数都是inline函数
    Computer(const char *brand,float price);
    void print()
    {
        cout<<"brand:"<<_brand<<endl
            <<"price:"<<_price<<endl;
    }
#if 0
    Computer(const Computer &rhs)
        :_brand(rhs.brand)
         ,_price(rhs.price)
    {
        cout<<"Computer(const Computer &)"<<endl;
    }
#endif
    Computer(const Computer &rhs)
        :_brand(new char[strlen(rhs._brand)+1]())
         ,_price(rhs._price)
    {
        cout<<"Computer(const Computer &)"<<endl;
        strcpy(_brand,rhs._brand);//深拷贝
    }
    ~Computer()
    {
        //必须提供一个析构函数，用来清理资源
        if(_brand)
        {
            delete []_brand;
            _brand=nullptr;//防止野指针的误用
        }
        cout<<"~Computer()"<<endl;
    }
protected://受保护的成员只会对其派生类或者子类开放
private:
    //private型成员自定义时在前面加上下划线
    char *_brand;
    float _price; 
};

Computer::Computer(const char *brand,float price)
    //:_brand(brand)//浅拷贝
    :_brand(new char[strlen(brand)+1]())
     ,_price(price)
{
    strcpy(_brand,brand);
    cout<<"Computer(const char *,float)"<<endl;
}

int test0()
{
    cout<<"sizeof(Computer)="<<sizeof(Computer)<<endl;
    Computer pc1("AppleMacBookPro",17000);//当对象的生命周期结束时，会自动调用析构函数
    pc1.print();
    
    static int number=0;//全局静态区
    ++number;
    cout<<"number="<<number<<endl;

    static Computer pc2("MSI",7777);//全局静态区
    return 0;
}

//Computer pc2("Huawei",6666);

int test1()
{
    Computer *p1=new Computer("ThinkpadT480",8888);
    p1->print();
    delete p1;//调用析构函数

    test0();
    return 0;
}

void test2()
{
    Computer pc1("Xiaomi",7777);
    cout<<"pc1="<<endl;
    pc1.print();
    cout<<endl;
    
    //用一个已经存在的对象初始化另一个新对象
    Computer pc2=pc1;//调用复制构造函数
    cout<<"pc2="<<endl;
    pc2.print();
}

//值传递--》进行复制
void display(Computer com)
{
    cout<<"com=";
    com.print();
}

void test3()
{
    Computer pc1("Thinkpad",8888);
    display(pc1);
}

Computer getComputer()
{
    Computer pc1("Thinkpad",8888);
    cout<<"pc1=";
    pc1.print();
    return pc1;//存在复制
}

void test4()
{
    Computer pc2=getComputer();
    cout<<"pc2=";
    pc2.print();
}

int main()
{
    //test2();
    //test3();
    test4();
    return 0;
}
