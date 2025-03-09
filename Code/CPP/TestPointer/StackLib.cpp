#include <iostream>

template <typename T>
struct Node
{
    T &value;
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
        Node<T> *node = new Node<T>();
        // 值传递 本体修改不会影响栈中的数据
        node->value = data;
        node->next = _top;
        _top = node;
        _count++;
    }

    // 以下三种函数的声明方式有什么区别
    // bool Pop(T result)
    // bool Pop(T *result)
    bool Pop(T &result)
    {
        std::cout << "调用Pop函数" << std::endl;
        if (_top == NULL)
        {
            std::cout << "栈为空, 不能够Pop" << std::endl;
            return false;
        }

        result = _top->value ;
        Node<T> *oldTop = _top;
        _top = _top->next;
        _count--;
        // oldTop = nullptr;
        delete oldTop;
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