// C++的模版不能到C#层才确定,因此需要在C++侧的桥接层把想要使用的类型全部写下来封装成接口
// 供C#侧调用
#include "StackLib.h"

extern "C"{
    DLL_PUBLIC Stack<int> *CreateStack_Int();
    DLL_PUBLIC bool DestroyStack_Int(Stack<int> *stack);
    DLL_PUBLIC void Push_Int(Stack<int> *stack, int &result);
    DLL_PUBLIC bool Pop_Int(Stack<int> *stack, int &result);
    DLL_PUBLIC bool Peek_Int(Stack<int> *stack, int &result);
    DLL_PUBLIC bool IsEmpty_Int(Stack<int> *stack);

    Stack<int> *CreateStack_Int(){
        return new Stack<int>();
    }

    bool DestroyStack_Int(Stack<int> *stack){
        if (stack->Delete()){
            return true;
        }

        return false;
    }

    void Push_Int(Stack<int> *stack, int &result){
        stack->Push(result);
    }

    bool Pop_Int(Stack<int> *stack, int &result){
        if(stack->Pop(result)){
            return true;
        }

        return false;
    }
    bool Peek_Int(Stack<int> *stack, int &result){
        if(stack->Peek(result)){
            return true;
        }
        return false;
    }
    bool IsEmpty_Int(Stack<int> *stack){
        return stack->IsEmpty();
    }

    DLL_PUBLIC Stack<wchar_t> *CreateStack_String();
    DLL_PUBLIC bool DestroyStack_String(Stack<wchar_t> *stack);
    DLL_PUBLIC void Push_String(Stack<wchar_t> *stack, wchar_t &result);
    DLL_PUBLIC bool Pop_String(Stack<wchar_t> *stack, wchar_t &result);
    DLL_PUBLIC bool Peek_String(Stack<wchar_t> *stack, wchar_t &result);
    DLL_PUBLIC bool IsEmpty_String(Stack<wchar_t> *stack);

    Stack<wchar_t> *CreateStack_String(){
        return new Stack<wchar_t>();
    }

    bool DestroyStack_String(Stack<wchar_t> *stack){
        if(stack->Delete()){
            return true;
        }

        return false;
    }

    void Push_String(Stack<wchar_t> *stack, wchar_t &result){
        stack->Push(result);
    }

    bool Pop_String(Stack<wchar_t> *stack, wchar_t &result){
        if (stack->Pop(result))
        {
            return true;
        }

        return false;
    }

    bool Peek_String(Stack<wchar_t> *stack, wchar_t &result){
        if (stack->Peek(result))
        {
            return true;
        }
        return false;
    }

    bool IsEmpty_String(Stack<wchar_t> *stack){
        return stack->IsEmpty();
    }

    DLL_PUBLIC Stack<float> *CreateStack_Float();
    DLL_PUBLIC bool DestroyStack_Float(Stack<float> *stack);
    DLL_PUBLIC void Push_Float(Stack<float> *stack, float &result);
    DLL_PUBLIC bool Pop_Float(Stack<float> *stack, float &result);
    DLL_PUBLIC bool Peek_Float(Stack<float> *stack, float &result);
    DLL_PUBLIC bool IsEmpty_Float(Stack<float> *stack);

    Stack<float> *CreateStack_Float() {
        return new Stack<float>();
    }

    bool DestroyStack_Float(Stack<float> *stack){
        if (stack->Delete())
        {
            return true;
        }

        return false;
    }

    void Push_Float(Stack<float> *stack, float &result) {
        stack->Push(result);
    }

    bool Pop_Float(Stack<float> *stack, float &result) {
        if(stack->Pop(result)){
            return true;
        }

        return false;
    }

    bool Peek_Float(Stack<float> *stack, float &result) {
        if(stack->Peek(result)){
            return true;
        }

        return false;
    }

    bool IsEmpty_Float(Stack<float> *stack){
        return stack->IsEmpty();
    }

    DLL_PUBLIC Stack<bool> *CreateStack_Bool();
    DLL_PUBLIC bool DestroyStack_Bool(Stack<bool> *stack);
    DLL_PUBLIC void Push_Bool(Stack<bool> *stack, bool &result);
    DLL_PUBLIC bool Pop_Bool(Stack<bool> *stack, bool &result);
    DLL_PUBLIC bool Peek_Bool(Stack<bool> *stack, bool &result);
    DLL_PUBLIC bool IsEmpty_Bool(Stack<bool> *stack);

    Stack<bool> *CreateStack_Bool(){
        return new Stack<bool>();
    }

    bool DestroyStack_Bool(Stack<bool> *stack){
        if (stack->Delete())
        {
            return true;
        }

        return false;
    }

    void Push_Bool(Stack<bool> *stack, bool &result){
        stack->Push(result);
    }

    bool Pop_Bool(Stack<bool> *stack, bool &result){
        if (stack->Pop(result))
        {
            return true;
        }

        return false;
    } 

    bool Peek_Bool(Stack<bool> *stack, bool &result){
        if (stack->Peek(result))
        {
            return true;
        }

        return false;
    } 

    bool IsEmpty_Bool(Stack<bool> *stack){
        return stack->IsEmpty();
    }
        
}