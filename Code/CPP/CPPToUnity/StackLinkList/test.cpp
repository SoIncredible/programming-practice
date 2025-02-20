#include <iostream>
#include <vector>
#include "StackLib.h"

class CustomClass{
    private:
        int value;
    public:
        CustomClass() {

        };

        CustomClass(int valueP){
            value = valueP;
        };

        void SomeFunc()
        {
            std ::cout << "执行" << value << std ::endl;
        };
};

int main(){
    int value;
    // 测试int类型
    std::cout << "测试int" << std::endl;
    Stack<int> *s = new Stack<int>();
    s->Push(1);

    std::cout << "数量" << s->Count() << std :: endl;
    if (s->Pop(value)){
        std::cout << value << std ::endl;
    }
    
    bool isEmpty = s->IsEmpty();
    if(isEmpty){
        std::cout << "栈是空的" << std::endl;
    }
    if(s->Peek(value)){
        std::cout << "PeekValue" << value << std::endl;
    }

    // 测试自定义类型栈
    std::cout << "测试自定义类型" << std::endl;
    Stack<CustomClass*> *r = new Stack<CustomClass*>();
    CustomClass *r1 = new CustomClass(1);
    CustomClass *r2 = new CustomClass(2);

    r->Push(r1);
    r->Push(r2);

    CustomClass *top;
    if(r->Pop(top)){
        top->SomeFunc();
    }

    if (r->Pop(top))
    {
        top->SomeFunc();
    }
    // std :: vector<int> vec1;
    // std ::vector<CustomClass*> vec2;
    // vec2.push_back(r1);

    return 0;
}