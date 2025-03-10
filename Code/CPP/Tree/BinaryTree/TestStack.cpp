#include <iostream>
// #include "StackLib.h"
#include "QueueLib.h"

class custom{
public:
    int data;

    custom() {

    };

    custom(int data1){
        data = data1;
    };
};

int main(){
    custom c1 = custom(1);
    custom c2 = custom(2);
    custom c3 = custom(3);

    // Stack<custom> *s = new Stack<custom>();
    Queue<custom> *q = new Queue<custom>();

    c1.data = 222;
    // s->Push(c1);
    // s->Push(c2);
    // s->Push(c3);

    q->EnQueue(c1);
    q->EnQueue(c2);
    q->EnQueue(c3);

    custom *peek;
    while(!q->IsEmpty()){
        peek = q->DeQueue();
        std::cout << peek->data << std::endl;
    }
    // peek = s->Peek();

    // peek->data = 666;
    // std::cout << peek->data << std ::endl;
    // while (!s->IsEmpty())
    // {
    //     int count = s->Count();
    //     std::cout << "数量" << count << std ::endl;
    //     peek = s->Pop();
    //     std ::cout << peek->data << std ::endl;
    // }

    // delete s;
    delete q;

    return 0;
}