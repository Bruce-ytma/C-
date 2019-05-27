//
//拷贝构造函数
//
#include<iostream>
using std::cout;
using std::endl;

class Cexample
{
public:
    Cexample(int a)
    {
        _a=a;
    }

    Cexample(const Cexample &C)
    {
        _a=C._a;
    }

    void show()
    {
        cout<<"a="<<_a<<endl;
    }
private:
    int _a;
};

int main()
{
    Cexample A(100);
    Cexample B=A;
    B.show();
    return 0;
}
