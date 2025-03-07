#include <iostream>
// #include <cstddef>
// 基于链表实现Stack数据结构
// 支持int float string char
template <typename T>
struct Node
{
    T *value;
    Node *next;
};

template <typename T>
class Stack
{

private:
    Node<T> *_top;
    int _count;

public:
    Stack()
    {
        std :: cout << "调用构造函数" << std ::endl;
        _top = NULL;
        _count = 0;
    }

    ~Stack()
    {
        std::cout << "调用析构函数" << std::endl;
        while (_top != NULL)
        {
            Node<T> *temp = _top;
            _top = _top->next;
            delete temp;
        }
    }

    void Push(T data)
    {
        Node<T> *node = new Node();
        node->value = *data;
        node->next = _top;
        _top = node;
        _count++;
    }

    bool Pop(T &result)
    {
        std::cout << "调用Pop函数" << std::endl;
        if (_top == NULL)
        {
            std::cout << "栈为空, 不能够Pop" << std::endl;
            return false;
        }

        result = _top->value;
        Node<T> *oldTop = _top;
        _top = _top->next;
        _count--;
        // 这个delete删除的是指针占用的内存空间吧? 指针指向的位置不受影响?
        oldTop = nullptr;
        // delete *oldTop; // 释放栈顶节点的内存
        return true;
    }

    bool Peek(T &result)
    {
        std ::cout << "调用Peek函数" << std ::endl;
        if (_top == NULL)
        {
            std::cout << "栈为空, 不能够Pop" << std::endl;
            return false;
        }
        result = _top->value;
        return true;
    }

    bool IsEmpty()
    {
        std ::cout << "调用IsEmpty函数" << std ::endl;
        return _count == 0;
    }

    int Count()
    {
        std ::cout << "调用Count函数" << std ::endl;
        return _count;
    }
};