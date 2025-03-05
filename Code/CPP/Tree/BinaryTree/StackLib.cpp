#include <iostream>
// #include <cstddef>
// 基于链表实现Stack数据结构
// 支持int float string char
template <typename T>
struct Node
{
    T value;
    Node *next;
};

template <typename T>
class Stack
{

private:
    Node<T> *top;

public:
    Stack()
    {
        std :: cout << "调用构造函数" << std ::endl;
        top = NULL;
    }

    ~Stack()
    {
        std::cout << "调用析构函数" << std::endl;
        while (top != NULL)
        {
            Node<T> *temp = top;
            top = top->next;
            delete temp;
        }
    }

    void Push()
    {
        std ::cout << "调用Push函数" << std ::endl;
    }

    bool Pop(T &result)
    {
        std::cout << "调用Pop函数" << std::endl;
        if (top == NULL)
        {
            std::cout << "栈为空, 不能够Pop" << std::endl;
            return false;
        }

        result = top->value;
        Node<T> *oldTop = top;
        top = top->next;
        delete oldTop; // 释放栈顶节点的内存
        return true;
    }

    bool Peek(T &result)
    {
        std ::cout << "调用Peek函数" << std ::endl;
        if (top == NULL)
        {
            std::cout << "栈为空, 不能够Pop" << std::endl;
            return false;
        }
        result = top->value;
        return true;
    }

    bool IsEmpty()
    {
        std ::cout << "调用IsEmpty函数" << std ::endl;
        return true;
    }

    int Count()
    {
        std ::cout << "调用Count函数" << std ::endl;
        return 0;
    }
};