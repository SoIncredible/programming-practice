#include <iostream>
#include "StackLib.h"

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

    Stack<custom> *s = new Stack<custom>();

    s->Push(c1);
    s->Push(c2);
    s->Push(c3);

    c3.data = 66;

    custom peek;
    custom& peek1 = s->Peek();
    peek1.data = 78;

    while(!s->IsEmpty()){
        peek1 = s->Pop();
        c1 = 222;
        std ::cout << peek1.data << std ::endl;
    }



    delete s;

    return 0;
}