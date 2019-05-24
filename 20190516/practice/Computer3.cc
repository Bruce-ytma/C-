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
    Computer()
        :_brand(nullptr)
         ,_price(0)
    {}
    Computer(const char *brand,float price);
    Computer(const Computer &rhs);
    Computer &operator=(const Computer &rhs);
    //void print()
    //{
    //    cout<<"brand:"<<_brand<<endl
    //        <<"price:"<<_price<<endl;
    //}
#if 0
    Computer(const Computer &rhs)
        :_brand(rhs.brand)
         ,_price(rhs.price)
    {
        cout<<"Computer(const Computer &)"<<endl;
    }
#endif

    //1.复制构造函数的引用可不可以删除？不能删除，因为如果删除，在调用复制构造函数时
    //会导致无穷递归，直到栈溢出
    //2.const可不可以删除？不可以
    //Computer(const Computer &rhs);
   //     :_brand(new char[strlen(rhs._brand)+1]())
   //      ,_price(rhs._price)
   // {
   //     cout<<"Computer(const Computer &)"<<endl;
   //     strcpy(_brand,rhs._brand);//深拷贝
   // }
    
    void print();

#if 0
    ~Computer()
    {}
#endif

    
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

Computer::Computer(const Computer &rhs)
    //:_brand(brand)//浅拷贝
    :_brand(new char[strlen(rhs._brand)+1]())
     ,_price(rhs._price)
{
    strcpy(_brand,rhs._brand);//深拷贝
    cout<<"Computer(const char *,float)"<<endl;
}

//系统提供的
//Computer &Computer::operator=(const Computer &rhs)
//{
//    _brand=rhs._brand;
//    _price=rhs._price;
//    cout<<"Computer & operator=(const Computer&)"<<endl;
//}

//this指针是一个隐含的参数
Computer &Computer::operator=(const Computer &rhs)
{
    cout<<"Computer & operator=(const Computer&)"<<endl;
    if(this!=&rhs)
    {

        delete []_brand;

        //深拷贝
        _brand=new char[strlen(rhs._brand)+1]();
        strcpy(_brand,rhs._brand);
        _price=rhs._price;
    }
    return *this;
}

void Computer::print()
{
    printf("&_brand=%p\n",_brand);
    cout<<">>brand:"<<this->_brand<<endl
        <<">>price:"<<this->_price<<endl;
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
    //&getComputer();//右值，称为临时对象，匿名对象
    //cout<<"pc2=";
    //pc2.print();
    
    int number=1;
    //&10;//error
    //int &ref=10;//error 非const引用不能绑定到右值
    const int &ref=10;//const引用可以绑定到右值
    const int &ref2=number;//const引用啥都可以绑定
    //Computer &rhs=getComputer();
}

void test5()
{
    Computer pc1("Xiaomi",8888),pc2("Thinkpad",9999);
    cout<<"pc1>>";
    pc1.print();
    cout<<"pc2>>";
    pc2.print();
    pc1=pc2;//左操作数，右操作数
    pc1.operator=(pc2);//完整形式
    cout<<"执行赋值操作之后："<<endl;
    cout<<"pc1>>";
    pc1.print();
    cout<<"pc2>>";
    pc2.print();

    Computer pc3("MSI",6666);
    pc1=pc2=pc3;
}

int main()
{
    //test2();
    //test3();
    //test4();
    test5();
    return 0;
}
