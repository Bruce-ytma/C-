//
//队列的类模板
//
#include <iostream>
using std::cout;
using std::endl;
using std::string;

template<typename Type,int kSize=10>
class Queue
{
public:
    Queue()
        :_head(0)
        ,_tail(0)
        ,_data(new Type[kSize]())
    {
        cout<<"Queue()"<<endl;
    }

    ~Queue()
    {
        if(_data)
        {
            delete []_data;
            cout<<"~Queue()"<<endl;
        }
    }

    bool empty()const;
    bool full()const;
    void insert(const Type &q);
    void Delete(const Type &q);
    Type front();
    Type rear();
private:
    int _head;
    int _tail;
    Type *_data;
};

template<typename Type,int kSize>
bool Queue<Type,kSize>::empty()const
{
    return _head==_tail;
}

template<typename Type,int kSize>
bool Queue<Type,kSize>::full()const
{
    return _head==kSize;
}

template<typename Type,int kSize>
void Queue<Type,kSize>::insert(const Type &q)
{
    if(full())
    {
        cout<<"The Queue is full."<<endl;
    }
    else
    {
        _data[++_head]=q;
    }
}

template<typename Type,int kSize>
void Queue<Type,kSize>::Delete(const Type &q)
{
    if(empty())
    {
        cout<<"The Queue is empty."<<endl;
    }
    else
    {
        _data[++_tail]=q;
    }
}

int main()
{
    Queue<string>queue;
    cout<<"此时队列是否为空？"<<queue.empty()<<endl;
    queue.insert("aaa");
    cout<<"此时队列是否为空？"<<queue.empty()<<endl;
    queue.insert("bbb");
    cout<<"此时队列是否已满？"<<queue.full()<<endl;
    queue.Delete("aaa");
    cout<<"此时队列是否已满？"<<queue.full()<<endl;
    return 0;
}

