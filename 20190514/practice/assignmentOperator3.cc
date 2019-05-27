//
//赋值运算符的重载
//
#include<string.h>
#include <iostream>
using std::cout;
using std::endl;

class String
{
public:
    String()
        :_str(NULL)
    {
        cout<<"String()"<<endl;
    }

    //因为不希望外界能够修改返回指针所指向的内容，所以这里
    //返回const指针
    const char *c_str()
    {
        return _str;
    }

    char *operator =(const char *rhs)
    {
        if(_str)
            delete []_str;
        if(rhs)
        {
            _str=new char[strlen(rhs)+1];//因为要添加末尾的'\0',所以要+1
            strcpy(_str,rhs);
        }
        else
            _str=NULL;
        return _str;
    }

    ~String()
    {
        if(_str)
        {
            delete []_str;
        }
    }
private:
    char *_str;
};

int main()
{
    String str;
    str="good luck,";
    //rhs.operator =("good luck,");
    cout<<str.c_str();
    str="kobe";
    cout<<str.c_str()<<endl;
    return 0;
}

