#include <iostream>
//using namespace std;//using编译指令
using std::cout;//using声明机制
using std::endl;

int number=10;
namespace wd
{
void display();
}
namespace tls
{
int number=11;
void display()
{
    cout<<"tls::display()"<<endl;
    wd::display();
}
}//end of namespace tls;

namespace wd
{
//在命名空间中可以定义任意的实体
int number=100;
void display()
{
    cout<<"wd::display()"<<endl;
}

void show()
{
    cout<<"wd::show()"<<endl;
    tls::display();
}

namespace ytma
{
int number=1;

void display(int number)
{
    cout<<"wd::ytma::display1()"<<endl;
    //cout<<"wd::ytma::number="<<number<<endl;//就近原则
    cout<<"wd::ytma::number="<<ytma::number<<endl;
    cout<<"wd::number="<<wd::number<<endl;
    cout<<"形参number="<<number<<endl;//形参number
    cout<<"全局number="<<::number<<endl;//全局number(匿名的命名空间)
}
}//end of namespace ytma;

}//end of namespace wd;

using wd::display;

int main(void)
{
    wd::show();
    return 0;
}

