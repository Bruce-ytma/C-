#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
    Base()
    {
        cout<<"Base()"<<endl;
    }

    virtual void print()
    {
        cout<<"Base::print()"<<endl;
    }
};

class Derived:public Base
{
public:
    Derived()
    {
        cout<<"Derived()"<<endl;
    }

    void print()
    {
        cout<<"Derived::print()"<<endl;
    }
};

int main()
{
    Base *p;
    p=new Derived();
    p->print();
    return 0;
}

