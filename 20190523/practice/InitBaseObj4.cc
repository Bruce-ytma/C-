//定义一个基类Student(学生)，再定义Student类的公用派生类
//Graduate(研究生)， 用指向基类对象的指针输出数据。本例主要
//是说明用指向基类对象的指针指向派生类对象，为了减少程序长度，
//在每个类中只设很少成员。学生类只设num(学号)
#include<string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;

class Student
{
public:
    Student(int,string,float);//声明构造函数
    void display();//声明输出函数
private:
    int _num;
    string _name;
    float _score;
};

Student::Student(int num,string name,float score)
{
    _num=num;
    _name=name;
    _score=score;
}

void Student::display()//定义输出函数
{
    cout<<"num:"<<_num<<endl
        <<"name:"<<_name<<endl
        <<"score:"<<_score<<endl;
}

class Graduate:public Student
{
public:
    Graduate(int,string,float,float);//声明构造函数
    void display();//声明输出函数
private:
    float _pay;
};

Graduate::Graduate(int num,string name,float score,float pay)
    :Student(num,name,score)
    ,_pay(pay)
{
    cout<<"Graduate(int,string,float,float)"<<endl;
}

void Graduate::display()//定义输出函数
{
    Student::display();//调用Student类的display函数
    cout<<"pay:"<<_pay<<endl;
}

int main()
{
    Student stu(1001,"li",98.5);//定义Student类对象stu
    Graduate grad(2001,"ma",99.5,555.5);//定义Graduate类对象grad
    Student *ps=&stu;//定义Student类对象的指针并指向stu
    ps->display();//调用Student的display函数
    ps=&grad;
    ps->display();//调用Graduate的display函数

    Graduate *pg=&grad;
    pg->display();
    return 0;
}

