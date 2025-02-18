#include "StackLib.h"

extern "C" {

    DLL_PUBLIC Stack *CreateStack();
    DLL_PUBLIC void DestroyStack(Stack *stackWrapper);
    DLL_PUBLIC void Push(Stack *stackWrapper, int value);
    DLL_PUBLIC int Pop(Stack *StackWrapper);
    DLL_PUBLIC bool IsEmpty(Stack *StackWrapper);

    Stack* CreateStack(){
        return new Stack();
    }

    void DestroyStack(Stack* stackWrapper){
        stackWrapper->DestroyStack(stackWrapper);
    }

    void Push(Stack* StackWrapper, int value){
        StackWrapper->Push(StackWrapper, value);
    }

    int Pop(Stack* StackWrapper){
        return StackWrapper->Pop(StackWrapper);
    }

    bool IsEmpty(Stack* StackWrapper){
        return StackWrapper->IsEmpty(StackWrapper);
    }
}