///*************************************************************************
///     @FileName: mvc.cc
///     @Author:   ytma
///     @Email:    1539447319@qq.com
///     @Time:     2019-06-07 23:49:43
///*************************************************************************
#include <iostream>
#include <map>
#include <string>
#include <memory>
using namespace std;

class Student
{
public:
    explicit
    Student(size_t id=0,const string &name=string())
    :_id(id)
    ,_name(name)
    {
        cout<<"Student(size_t,const string)"<<endl;
    }

    size_t getId()const
    {
        return _id;
    }

    string getName()const
    {
        return _name;
    }

    void setId(size_t id)
    {
        _id=id;
    }

    void setName(const string &name)
    {
        _name=name;
    }
private:
    size_t _id;
    string _name;
};

class View
{
public:
    View(Student *student=nullptr)
        :_student(student)
    {
        cout<<"View(Student *)"<<endl;
    }

    void reset(Student *student)
    {
        _student=student;
    }

    virtual void show()const
    {
        cout<<"id:"<<_student->getId()<<endl
            <<"name:"<<_student->getName()<<endl;
    }

    virtual ~View()
    {}
protected:
    Student *_student;
};

class SubView:public View
{
public:
    explicit
    SubView(Student *student=nullptr)
    :View(student)
    {
        cout<<"SubView(Student *)"<<endl;
    }

    void show()const
    {
        cout<<"{id:"<<_student->getId()
            <<",name:"<<_student->getName()
            <<"}"<<endl;
    }
};

class Controller
{
public:
    Controller()
    {
        cout<<"Controller()"<<endl;
    }

    void attach(const Student &student)
    {
        _students.insert(make_pair(student.getId(),student));
    }

    void detach(size_t id)
    {
        _students.erase(id);
    }

    void find(size_t id)
    {
        auto it=_students.find(id);
        if(it!=_students.end())
        {
            SubView(&(it->second)).show();
        }
    }

    void show(View *view)
    {
        for(auto it=_students.begin();it!=_students.end();++it)
        {
            view->reset(&(it->second));
            view->show();
            cout<<endl;
        }
    }

private:
    map<size_t,Student> _students;
};

int main()
{
    Controller controller;
    controller.attach(Student(1,"Mike"));
    controller.attach(Student(2,"Jackie"));
    controller.attach(Student(3,"Mary"));
    
    unique_ptr<View> view(new View());
    controller.show(view.get());

    unique_ptr<View> view2(new SubView);
    controller.show(view2.get());

    controller.find(1);

    return 0;
}

