#include <iostream>
using std::cout;
using std::endl;

int test0()
{
    int number=100;
    int &ref=number;
    cout<<"number="<<number<<endl
        <<"ref="<<ref<<endl;
    cout<<endl;

    ref=1;
    cout<<"number="<<number<<endl
        <<"ref="<<ref<<endl;
    
    //int &ref2;//引用必需要进行初始化
    int number2=10;
    ref=number2;//(ref表达的是引用，改变指向)1.将number2赋给ref；2.ref指向number2
                //引用一经绑定，不会再改变其指向
    cout<<"number="<<number<<endl
        <<"ref="<<ref<<endl
        <<"number2="<<number<<endl;
    return 0;
}

//将引用作为函数的参数进行传递

//值传递--》进行复制
//void swap(int x,int y)
//{
//    int temp=x;
//    x=y;
//    y=temp;
//}

//地址传递--》本质就是值传递--》本质就是复制
//void swap(int *px,int *py)
//{
//    int temp=*px;
//    *px=*py;
//    *py=temp;
//}

//引用传递，优势就是绑定实参，对形惨的操作与实参保持一致
//参数的传递效率更高,在形式上更容易理解，更直观
void swap(int &x,int &y)
{
    int temp=x;
    x=y;
    y=temp;
}

int main()
{
    int number1=3,number2=4;
    cout<<"number1="<<number1<<endl
        <<"number2="<<number2<<endl;
    cout<<endl;
    //swap(number1,number2);
    //swap(&number1,&number2);
    swap(number1,number2);//int &x=number1,&y=number2;已经初始化了
    cout<<"number1="<<number1<<endl
        <<"number2="<<number2<<endl;
    return 0;
}
