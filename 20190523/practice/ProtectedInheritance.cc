//
//保护继承
//
#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
    Base(int pub=0,int pro=0,int pri=0)
        :_pub(pub)
        ,_pro(pro)
        ,_pri(pri)
    {
        cout<<"Base()"<<endl;
    }

    ~Base()
    {
        cout<<"~Base()"<<endl;
    }

    int _pub;
protected:
    int _pro;
private:
    int _pri;

};

class Derive:protected Base
{
public:
    Derive()
    {
        cout<<"Derive()"<<endl;
    }
    ~Derive()
    {
        cout<<"~Derive()"<<endl;
    }

    void distory()
    {
        cout<<"_pub="<<_pub<<endl;
        cout<<"_pro="<<_pro<<endl;
        //cout<<"_pri="<<_pri<<endl;
        cout<<"d_pub="<<d_pub<<endl;
        cout<<"d_pro="<<d_pro<<endl;
        cout<<"d_pri="<<d_pri<<endl;
    }
    
    int d_pub;
protected:
    int d_pro;
private:
    int d_pri;
};

int main()
{
    Derive p;
    p.distory();
    return 0;
}

