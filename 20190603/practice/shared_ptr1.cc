///*************************************************************************
///     @FileName: shared_ptr.cc
///     @Author:   ytma
///     @Email:    1539447319@qq.com
///     @Time:   Tue 04 Jun 2019 11:25:32 PM CST
///*************************************************************************
#include <iostream>
#include <memory>
using namespace std;

class Person
{
public:
    Person(int value)
        :_value(value)
    {
        cout<<"Person(int)"<<endl;
    }

    ~Person()
    {
        cout<<"~Person()"<<endl;
    }
private:
    int _value;
};

int main()
{
    shared_ptr<Person> p1(new Person(1));//Person(1)的引用计数为1
    shared_ptr<Person> p2=make_shared<Person>(2);
    p1.reset(new Person(3));//首先生成新对象，然后引用计数减1，
                            //引用计数为0，故析构Person(1)
                            //最后将新对象的指针交给智能指针
    shared_ptr<Person> p3=p1;//现在p1和p3同时指向Person(3),
                             //Person(3)的引用计数为2
    p1.reset();//Person(3)的引用计数为1
    p3.reset();//Person(3)的引用计数为0，析构Person(3)
    return 0;
}

