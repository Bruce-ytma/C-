#include <iostream>
using namespace std;

namespace wd
{
//在命名空间中可以定义任意的实体
int number=100;
void display()
{
    cout<<"wd::display()"<<endl;
}
}

int main(void)
{
    cout << "number=" <<wd::number<< endl;//::作用域限定符
    wd::display();
    return 0;
}

