#include <iostream>
using std::cout;
using std::endl;

int main()
{
    //编译选项：-fno-elide-constructors 作用：去掉对象创建时的优化操作
    std::string s1="hello,world";//std::string("hello,world");
    std::string s2=("hello,world");
    return 0;
}

