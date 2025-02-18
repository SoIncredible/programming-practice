#include "StackLib.h"

Stack::Stack(){
    stack = new StackWrapper();
}

// 创建栈实例
Stack * Stack::CreateStack()
{
    return new Stack();
}

// 销毁栈实例
void Stack::DestroyStack(Stack* stackWrapper) {
    if (stackWrapper) {
        delete stackWrapper;
    }
}

// 入栈操作
void Stack::Push(Stack *stackWrapper, int value)
{
    if (stackWrapper) {
        stackWrapper->stack->stack.push(value);
    }
}

// 出栈操作
int Stack::Pop(Stack *stackWrapper)
{
    if (stackWrapper && !stackWrapper->stack->stack.empty())
    {
        int value = stackWrapper->stack->stack.top();
        stackWrapper->stack->stack.pop();
        return value;
    }
    return -1; // 表示栈为空
}

// 判断栈是否为空
bool Stack::IsEmpty(Stack *stackWrapper)
{
    if (stackWrapper) {
        return stackWrapper->stack->stack.empty();
    }
    return true;
}