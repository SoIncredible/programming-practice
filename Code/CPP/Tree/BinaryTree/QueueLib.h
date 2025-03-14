#include <iostream>
#include "Node.h"

template <typename T>
class Queue
{
private:
    Node<T> *_head;
    Node<T> *_trail;
    int _count;

public:
    Queue();

    ~Queue();

    void EnQueue(T &data);

    void EnQueue(T *data);

    T* DeQueue();

    bool IsEmpty();

    int Count();

    void Reverse();
};

template <typename T>
Queue<T>::Queue(){
    _head = nullptr;
    _trail = nullptr;
    _count = 0;
};

template <typename T>
Queue<T>::~Queue(){
    while(_count > 0){
        Node<T> *h = _head;
        _head = _head->next;
        delete h;
        _count--;
    }
}

template <typename T>
void Queue<T>::EnQueue(T &data){
    Node<T> *node = new Node<T>();
    node->data = &data;
    node->next = nullptr;
    if (_count == 0)
    {
        _head = node;
        _trail = node;
    }
    else
    {
        _trail->next = node;
        _trail = node;
    }
    _count++;
}

template <typename T>
void Queue<T>::EnQueue(T* data){
    Node<T> *node = new Node<T>(); // 这个node申请的内存何时释放？
    node->data = data;
    node->next = nullptr;
    if(_count == 0){
        _head = node;
        _trail = node;
    }
    else
    {
        _trail->next = node;
        _trail = node;
    }
    _count++;
}

template <typename T>
T *Queue<T>::DeQueue() {
    if(_count == 0){
        throw std::range_error("队列为空,不能执行出队操作");
    }

    Node<T> *headNext = _head->next;
    T *data = _head->data;
    delete _head;
    _head = headNext;
    _count--;
    return data;
}

template <typename T>
bool Queue<T>::IsEmpty(){
    return _count == 0;
}

template <typename T>
int Queue<T>::Count(){
    return _count;
}

template <typename T>
void Queue<T>::Reverse(){
    
}
