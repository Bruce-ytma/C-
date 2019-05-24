#include <iostream>
using std::cout;
using std::endl;

class NullPointerCall
{
public:
    void func1()
    {   cout<<"func1()"<<endl;  }
    void func2(int ix)
    {   cout<<"ix="<<ix<<endl;  }
    void func3()
    {   cout<<"_ix="<<_ix<<endl;    }
private:
    int _ix;
};

int main()
{
    int *p1=nullptr;
    NullPointerCall *p=nullptr;
    p->func1();//NullPointerCall::func1(p);
    p->func2(10);//NullPointerCall::func2(p,10);
    //p->func3();//error  p->func3(p);
    
    NullPointerCall np;
    np.func1();//NullPointerCall::func1(&np);
    np.func2(10);
    np.func3();//np.func3(&np);
    return 0;
}

