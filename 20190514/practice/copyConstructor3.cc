#include <iostream>
using std::cout;
using std::endl;
using std::string;

class Student
{
public:
    Student(string name="",int age=0,float score=0.0f);//普通构造函数
    Student(const Student &stu);//拷贝构造函数的声明
    void display();
private:
    string _name;
    int _age;
    float _score;
};

Student::Student(string name,int age,float score)
    :_name(name)
    ,_age(age)
    ,_score(score)
{
    cout<<"Student(string,int,float)"<<endl;
}
//拷贝构造函数必须是当前类的引用
//如果不是当前类的引用，而是当前类的对象，那么在调用拷贝构造函数时，
//会将另外一个对象直接传递给形参，这本身就是一次拷贝，会再次调用拷贝
//构造函数，然后又将一个对象传递给了形参，将继续调用拷贝构造函数，这
//个过程一直持续下去，没有尽头，陷入死循环
//
//拷贝构造函数必须是const引用
//拷贝构造函数的目的是用其他对象的数据来初始化当前对象，所以必须是const
//另外一个原因是：添加const限制后，可以将const对象和非const对象传递给
//形参了，因为非const类型可以转换为const类型。如果没有const限制，就不能
//将const对象传递给形参，因为const类型不能转换为非const类型，这就意味着
//不能使用const对象来初始化当前对象了。
Student::Student(const Student &stu)
{
    this->_name=stu._name;
    this->_age=stu._age;
    this->_score=stu._score;
    cout<<"Student(const Student &)"<<endl;
}

void Student::display()
{
    cout<<"name:"<<_name<<endl
        <<"age:"<<_age<<endl
        <<"score:"<<_score<<endl;
}

int main()
{
    Student stu1("Mary",20,98.5);
    Student stu2=stu1;//调用拷贝构造函数
    Student stu3(stu1);//调用拷贝构造函数
    stu1.display();
    stu2.display();
    stu3.display();
    return 0;
}

