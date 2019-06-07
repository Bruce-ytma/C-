///*************************************************************************
///     @FileName: FriendClass.cc
///     @Author:   ytma
///     @Email:    1539447319@qq.com
///     @Time:     2019-06-07 10:34:42
///*************************************************************************
#include <iostream>
using namespace std;

class B
{
public:
    B(int b)
        :_b(b)
    {
        cout<<"B(int)"<<endl;
    }

    friend class C;//声明友元类，友元类的声明在类内部，实现则在该类的外部
private:
    int _b;
};

class C//实现友元类
{
public:
    int getB(B classB)
    {
        return classB._b;//访问友元类B的私有成员
    }
};

int main()
{
    B classB(3);
    C classC;//定义友元类实例
    cout<<classC.getB(classB)<<endl;
    return 0;
}

