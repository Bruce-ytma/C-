#include<stdio.h>
#include<string.h>

#include <iostream>
using std::cout;
using std::endl;
using std::string;

void test0()
{
    //c风格字符串
    int number=10;
    const char *pstr="hello,world";//(字符串)位于字符常量区，只读
    //*pstr='H';//error
    printf("&number=%p\n",&number);
    printf("pstr=%s\n",pstr);
    printf("pstr address=%p\n",pstr);

    char parray[]="hello,world";//(字符数组)在栈区  相当于strcpy(parray,"hello,world");
    printf("parray=%s\n",parray);
    printf("parray address=%p\n",&parray);

    printf("sizeof(parray)=%ld\n",sizeof(parray));
    printf("strlen(parray)=%ld\n",strlen(parray));

    for(int idx=0;idx!=sizeof(parray);++idx)
    {
        printf("%c",parray[idx]);
    }
    printf("\n");
}

void test1()
{
    string s1="hello,world";//将c风格的字符串转换为c++风格的字符串
    cout<<"s1="<<s1<<endl;
    //获取字符串的长度
    cout<<"s1's size="<<s1.size()<<endl;
    cout<<"s1's size="<<s1.length()<<endl;

    //遍历字符串
    for(int idx=0;idx!=s1.size();++idx)
    {
        cout<<s1[idx];
    }
    cout<<endl;

    //字符串拼接操作
    string s2="wangdao";
    string s3=s1+s2;
    cout<<"s3="<<s3<<endl;
}

int main()
{
    //test0();
    test1();
    return 0;
}

