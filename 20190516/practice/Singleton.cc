#include <iostream>
using std::cout;
using std::endl;

//单例设计模式：
//要求是：通过该类只能创建出一个对象
//1.该对象不能是栈对象、全局对象、只剩下一个堆对象

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

    static void free()
    {

    }

    void print()const
    {
        cout<<"singleton::print()"<<endl;
    }

    ~Singleton()
    {
        cout<<"~Singleton()"<<endl;
    }

private:
    Singleton(){ cout<<"Singleton()"<<endl;  }
    static Singleton *_pInstance;
};

Singleton *Singleton::_pInstance=nullptr;

//Singleton s1;//error

int main()
{
    //Singleton s2;//error
    //Singleton s3;
    //
    //Singleton *p1=new Singleton();//error
    Singleton *p1=Singleton::getInstance();
    Singleton *p2=Singleton::getInstance();
    //getInstance();
    cout<<"p1="<<p1<<endl
        <<"p2="<<p2<<endl;

    //更多的是这种用法
    Singleton::getInstance()->print();
    Singleton::free();//destory();delete();
    
    //delete p1;//error 希望该语句编译无法通过
    return 0;
}

