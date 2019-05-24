#include <iostream>
using std::cout;
using std::endl;

void display()
{
    cout<<"display()"<<endl;
}

void show()
{
    cout<<"show()"<<endl;
}

void (*p)()=display;

typedef void(*Function)();

int main()
{
    p();
    Function f1=display;
    f1();

    f1=show;
    f1();
    return 0;
}

