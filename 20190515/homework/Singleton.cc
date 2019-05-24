//
//单例设计模式
//
#include <iostream>
using std::cout;
using std::endl;

class Singleton
{
public:
    static Singleton *getInstance()
    {
        if(_pInstance==nullptr)
        {
            _pInstance=new Singleton();
        }
        return _pInstance;
    }

    static void destory()
    {
        if(_pInstance)
        {
            delete _pInstance;
        }
    }

    void print()const
    {
        cout<<"Singleton::print()"<<endl;
    }

private:
    Singleton()
    {
        cout<<"Singleton()"<<endl;
    }

    ~Singleton()
    {
        cout<<"~Singleton()"<<endl;
    }

    static Singleton *_pInstance;
};

Singleton *Singleton::_pInstance=nullptr;

int main()
{
    Singleton *p1=Singleton::getInstance();
    cout<<"*p1="<<p1<<endl;

    Singleton::getInstance()->print();

    Singleton::destory();
    return 0;
}

