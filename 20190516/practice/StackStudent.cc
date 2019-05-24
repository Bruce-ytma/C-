//
//new/delete工作机制
//
#include<string.h>
#include<stdlib.h>
#include <iostream>
using std::cout;
using std::endl;

class Student
{
public:
    Student(const char *name,int id)
        :_name(new char[strlen(name)+1]())
        ,_id(id)
    {
        cout<<"Student(const char *,int)"<<endl;
        strcpy(_name,name);
    }

    void Print()const
    {
        cout<<"name:"<<_name<<endl
            <<"id:"<<_id<<endl;
    }

    ~Student()
    {
        delete []_name;
        cout<<"~Student()"<<endl;
    }

    //重载操作
    //void *operator new(size_t sz)
    //{
    //    cout<<"void *operator new(size_t)"<<endl;
    //    void *ret=malloc(sz);
    //    return ret;
    //}

    //void operator delete(void *ret)
    //{
    //    cout<<"void operator delete(void *)"<<endl;
    //    free(ret);
    //}
private:
    void *operator new(size_t sz);
    void operator delete(void *ret);
private:
    char *_name;
    int _id;
};

int main()
{
    //Student *pstu=new Student("Mike",100);//error 编译不通过
    //pstu->Print();
    
    Student stu("Mary",101);
    stu.Print();
    //delete pstu;
    cout<<endl;

    int *p1=new int(1);
    cout<<"*p1="<<*p1<<endl;
    delete p1;

    cout<<endl;
    return 0;
}

