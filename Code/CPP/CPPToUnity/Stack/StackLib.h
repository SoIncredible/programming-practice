#ifndef STACKLIBRARY_H
#define STACKLIBRARY_H

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

#include <stack>

// 定义一个结构体来包装栈类
typedef struct StackWrapper
{
    std::stack<int> stack;
} StackWrapper;

class Stack{
    private:
        

    public:
        StackWrapper *stack;

        // 创建栈实例
        Stack *CreateStack();

        Stack();

        // 销毁栈实例
        void DestroyStack(Stack *stackWrapper);

        // 入栈操作
        void Push(Stack *stackWrapper, int value);

        // 出栈操作
        int Pop(Stack *stackWrapper);

        // 判断栈是否为空
        bool IsEmpty(Stack *stackWrapper);
};

#endif // STACKLIBRARY_H