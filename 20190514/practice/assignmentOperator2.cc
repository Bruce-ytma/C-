//
//赋值运算符
//
#include <iostream>
using std::cout;
using std::endl;

class Book
{
public:
    Book()
        :_price(0.0)
        ,_bookmark(NULL)
        ,_num(0)
    {
        cout<<"Book()"<<endl;
    }

    Book(double price,int *bookmark,int num)
        :_price(price)
        ,_num(num)
    {
        int *bmTemp=new int[num];
        for(int idx=0;idx<num;idx++)
        {
            bmTemp[idx]=bookmark[idx];
        }
        this->_bookmark=bmTemp;
    }

    void setBookmark(int page,int index)
    {
        if(index>=_num-1)
        {
            cout<<"Out of bound!"<<endl;
        }
        else
        {
            _bookmark[index]=page;
        }
    }

    Book &operator =(const Book &rhs)
    {
        if(this!=&rhs)
        {
            this->_price=rhs._price;
            this->_num=rhs._num;
            //为bookmark赋值
            int *bmTemp=new int[rhs._num];
            for(int idx=0;idx<rhs._num;idx++)
            {
                bmTemp[idx]=rhs._bookmark[idx];
            }
            this->_bookmark=bmTemp;
        }
        return *this;
    }

    void display()
    {
        cout<<"price:"<<_price<<endl
            <<"bookmark:";
        for(int idx=0;idx<_num;idx++)
        {
            if(idx=_num-1)
            {
                cout<<_bookmark[idx]<<endl;
            }
            else
            {
                cout<<_bookmark[idx]<<",";
            }
        }
    }
private:
    double _price;
    int *_bookmark;
    int _num;
};

int main()
{
    int _bookmark[]={1,49,56,290};

    Book java,cpp(68.5,_bookmark,4);
    cpp.display();
    java=cpp;
    java.setBookmark(100,2);
    cpp.display();
    return 0;
}

