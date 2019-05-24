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

int test1()
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

int array[5]={1,2,3,4,5};
int index(int idx)
{
    return array[idx];
}

//返回的是一个引用，就是一个左值
//返回的值其生命周期一定要是大于函数的声明周期的
int &index2(int idx)
{
    return array[idx];
}

//不能返回一个局部变量的引用
int &index3()
{
    int number=10;//局部变量，存在函数栈空间中，当函数执行完毕时，栈空间销毁
    return number;
    
}

void test2()
{
    cout<<"index(1)="<<index(1)<<endl;
    int number=index(1);
    cout<<"number="<<number<<endl;
    //index(1)=10;//左值就是能够存储在内存中，被持久化的变量
    //&index(1);//右值不能取地址，是一个临时变量

    &index2(0);
    index2(0)=10;
    cout<<"array[0]="<<array[0]<<endl;
}

void test3()
{
    cout<<"index3()="<<index3()<<endl;
    //int number=index3();//对变量number初始化
    int &number=index3();
    cout<<"number="<<number<<endl;
}

//不要轻易返回一个堆空间变量的引用；
//如果要返回，一定要想好内存回收的策略
int &getNumber()
{
    int *pNumber=new int(10);
    return *pNumber;
}

void test4()
{
    int number=getNumber();//对number进行初始化
    //int &number=getNumber();//直接拿到堆空间的值
    delete &number;

    int a=3,b=4;
    int c=a+getNumber()+b;//发生内存泄漏
}

int main()
{
    //test2();
    test3();
    return 0;
}
