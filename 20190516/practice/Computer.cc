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
    Computer(const char *brand,double price);
    Computer(const Computer &rhs);
    Computer &operator=(const Computer &rhs);
    
    void print();//非const成员函数
    //从现在开始，建议一个成员函数没有修改数据成员，就将它设为const成员函数
    void print()const;//const成员函数
    static void printTotalPrice(Computer *);
    
    void setPrice(double price)
    {
        _price=price;
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
        _totalPrice-=_price;
    }
protected://受保护的成员只会对其派生类或者子类开放
private:
    //private型成员自定义时在前面加上下划线
    char *_brand;
    double _price; 
    static double _totalPrice;//位于全局静态区
};
//静态成员的初始化要在类之外初始化
double Computer::_totalPrice=0;

Computer::Computer(const char *brand,double price)
    //:_brand(brand)//浅拷贝
    :_brand(new char[strlen(brand)+1]())
     ,_price(price)
{
    strcpy(_brand,brand);
    cout<<"Computer(const char *,double)"<<endl;
    _totalPrice+=_price;
}


Computer::Computer(const Computer &rhs)
    //:_brand(brand)//浅拷贝
    :_brand(new char[strlen(rhs._brand)+1]())
     ,_price(rhs._price)
{
    strcpy(_brand,rhs._brand);//深拷贝
    cout<<"Computer(const char *,double)"<<endl;
}

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

void Computer::print(/* Computer *const this */)
{
    cout<<"void Computer::print()"<<endl;
    printf("&_brand=%p\n",_brand);
    cout<<">>brand:"<<this->_brand<<endl
        <<">>price:"<<this->_price<<endl;
        //<<">>_totalPrice:"<<_totalPrice<<endl;
}

//const成员函数
//在内部不能访问非const的成员函数
//也不能修改对象的数据成员
void Computer::print(/* Computer const *const this */)const
{
    //setPrice(10000);
    //_price=10000;//error 有可能修改对象的数据成员
    cout<<"void Computer::print()const"<<endl;
    printf("&_brand=%p\n",_brand);
    cout<<">>brand:"<<this->_brand<<endl
        <<">>price:"<<this->_price<<endl;
        //<<">>_totalPrice:"<<_totalPrice<<endl;
}

//静态成员函数
void Computer::printTotalPrice(Computer *pc)
{
    //静态成员函数内部不能访问非静态的成员和成员函数，只能访问静态成员函数和数据成员
    //cout<<"_brand:"<<_brand<<endl;
    //原因：静态成员函数没有隐含的this指针
    cout<<"total price:"<<_totalPrice<<endl;
}

//普通函数、全局函数、自由函数
void print(Computer *pc)
{
    pc->print();
}

void test0()
{
    int number=10;
    const int number1=100;
    int *p=&number;
    //int *p2=&number1;//error
    const int *p3=&number;
}

int main()
{
    cout<<"sizeof(Computer)="<<sizeof(Computer)<<endl;
    Computer pc1("Xiaomi",8888);
    cout<<"pc1=";
    pc1.print();//当const版本与非const版本的成员函数同时定义
                //非const对象调用非const版本的成员函数
                //当只有const版本的成员函数时，非const对象也可以调用const成员函数
    //pc1.printTotalPrice();
    //Computer::printTotalPrice(&pc1);//静态成员函数可以直接通过类名调用
    //print(&pc1);

    cout<<endl;
    Computer pc2("Huawei",7777);
    cout<<"pc2=";
    pc2.print();
    //pc2.printTotalPrice();
    //Computer::printTotalPrice(&pc2);//静态成员函数可以直接通过类名调用
    //print(&pc2);
    
    cout<<endl;
    const Computer pc3("Thinkpad",6666);
    pc3.print();
    return 0;
}
