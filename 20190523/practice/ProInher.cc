#include <iostream>
using std::cout;
using std::endl;

class Student//基类的声明
{
public:
    Student()
    {
        _num=1;
        _name='M';
        _sex='m';
        cout<<"Student()"<<endl;
    }

    void show()const
    {
        cout<<"num:"<<_num<<endl
            <<"name:"<<_name<<endl
            <<"sex:"<<_sex<<endl;
    }
private:
    int _num;
    char _name;
    char _sex;
};

class Student1:protected Student//派生类的声明
{
public:
    Student1()
    {
        _age=16;
        cout<<"Student1()"<<endl;
    }

    void show1()const
    {
        show();
        cout<<"age:"<<_age<<endl;
    }
private:
    int _age;
};

int main()
{
    Student stu;
    stu.show();
    Student1 stu1;
    stu1.show1();
    return 0;
}

