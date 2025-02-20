#if defined _WIN32 || defined __CYGWIN__
#ifdef BUILDING_DLL
#ifdef __GNUC__
#define DLL_PUBLIC __attribute__((dllexport))
#else
#define DLL_PUBLIC __declspec(dllexport) // Note: actually gcc seems to also supports this syntax.
#endif
#else
#ifdef __GNUC__
#define DLL_PUBLIC __attribute__((dllimport))
#else
#define DLL_PUBLIC __declspec(dllimport) // Note: actually gcc seems to also supports this syntax.
#endif
#endif
#define DLL_LOCAL
#else
#if __GNUC__ >= 4
#define DLL_PUBLIC __attribute__((visibility("default")))
#define DLL_LOCAL __attribute__((visibility("hidden")))
#else
#define DLL_PUBLIC
#define DLL_LOCAL
#endif
#endif

#include <iostream>
// 基于链表实现Stack数据结构

template <typename T>
class Stack{

private:
    struct Node
    {
        T data;
        Node *next;
        Node(const T& value) : data(value), next(nullptr){}
    };

    Node *top;

public:
    Stack()
    {
        // std :: cout << "调用构造函数" << std ::endl;
        top = nullptr;
    }

    ~Stack()
    {
        // std::cout << "调用析构函数" << std::endl;
        while (top != nullptr)
        {
            Node *temp = top;
            top = top->next;
            delete temp;
        }
    }

    void Push(const T& value)
    {
        // std ::cout << "调用Push函数" << std ::endl;
        Node *newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    bool Pop(T& result)
    {
        // std::cout << "调用Pop函数" << std::endl;
        if (top == nullptr)
        {
            std::cout << "栈为空, 不能够Pop" << std::endl;
            return false;
        }

        result = top->data;
        Node *oldTop = top;
        top = top->next;
        delete oldTop; // 释放栈顶节点的内存
        return true;
    }

    bool Peek(T &result)
    {
        if (top == nullptr)
        {
            std::cout << "栈为空" << std::endl;
            return false;
        }
        result = top->data;
        return true;
    }

    bool IsEmpty()
    {
        if(top != nullptr){
            return false;
        }
        return true;
    }

    int Count()
    {
        Node *temp = top;

        int count = 0;
        while (temp != nullptr)
        {
            temp = temp->next;
            count++;
        }
        return count;
    }

    bool Delete(){
        // if(this != nullptr){
            delete this;
            return true;
        // }

        // return false;
    }
};