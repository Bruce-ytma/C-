#include <iostream>
using std::cout;
using std::endl;

class CSingleton
{
private:
    CSingleton()   //构造函数是私有的
    {
    }
    static CSingleton *m_pInstance;
public:
    static CSingleton * GetInstance()
    {
        if(m_pInstance == NULL)  //判断是否第一次调用
            m_pInstance = new CSingleton();
        return m_pInstance;

    }

};

CSingleton *CSingleton::m_pInstance=nullptr;//静态成员函数要在类外进行初始化

int main()
{
    CSingleton *p1 = CSingleton :: GetInstance();
    CSingleton *p2 = CSingleton :: GetInstance();
    //CSingleton* p2 = p1->GetInstance();
    //CSingleton & ref = * CSingleton :: GetInstance();
    cout<<"*p1="<<p1<<endl
        <<"*p2="<<p2<<endl;
    return 0;
}
