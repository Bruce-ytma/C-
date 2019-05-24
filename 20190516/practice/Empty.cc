#include <iostream>
using std::cout;
using std::endl;

//空类占据的存储空间是1个字节，因为通过可以创建不同的对象，既然是不同的对象
//所以必须要有不同的空间来进行存储，所以还是给1个字节的空间
class Empty
{};

int main()
{
    Empty e1;
    cout<<"&e1="<<&e1<<endl;
    Empty e2;
    cout<<"&e2="<<&e2<<endl;
    cout<<"sizeof(Empty)="<<sizeof(Empty)<<endl;
    return 0;
}

