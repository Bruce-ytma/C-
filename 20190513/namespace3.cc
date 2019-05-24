#include <iostream>
//using namespace std;//using编译指令
using std::cout;//using声明机制
using std::endl;

int number=10;

namespace wd
{
//在命名空间中可以定义任意的实体
int number=100;
void display()
{
    cout<<"wd::display()"<<endl;
}

namespace ytma
{
int number=1;

void display1(int number)
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

namespace tls
{
int number=11;
}//end of namespace tls;

using wd::display;
//using wd::number;//error
//using tls::number;

int main(void)
{
    return 0;
}

