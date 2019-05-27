//
//类对象的拷贝
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
