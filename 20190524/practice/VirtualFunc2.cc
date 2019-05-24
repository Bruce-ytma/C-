#include <iostream>
using std::cout;
using std::endl;

class Person
{
public:
    Person()
    {
        cout<<"Person()"<<endl;
    }
    ~Person()
    {
        cout<<"~Person()"<<endl;
    }
};

class Teacher:virtual public Person
{
public:
    Teacher()
    {
        cout<<"Teacher()"<<endl;
    }
    ~Teacher()
    {
        cout<<"~Teacher()"<<endl;
    }
};

class Student:virtual public Person
{
public:
    Student()
    {
        cout<<"Student()"<<endl;
    }
    ~Student()
    {
        cout<<"~Student()"<<endl;
    }
};

class Ts:public Teacher,public Student
{
public:
    Ts()
    {
        cout<<"Ts()"<<endl;
    }
    ~Ts()
    {
        cout<<"Ts()"<<endl;
    }
};

int main()
{
    Ts ts;
    return 0;
}

