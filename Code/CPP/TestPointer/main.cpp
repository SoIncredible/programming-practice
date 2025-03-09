
#include<iostream>

struct Node{
    int Data;
    Node *next;
};

class someS{

private:
    Node *n;
    // 这里面有一个存储结构
public:

    someS(){
        n = new Node();
        n->next = nullptr;
        n->Data = -1;
    }

    void Store(Node node){
        Node *nn = &node;
        n->next = nn;
    }
    void Load();
};

int main(){

    // Node* node = new Node();
    // node->Data = 2;
    // node->next = nullptr;
    // Node origin = *node;

    // Node *another = node;

    // std::cout << origin.Data << std::endl;
    // std::cout << another->Data << std::endl;

    // // another = nullptr;
    // // delete another;

    // origin.Data = 33;
    // std::cout << origin.Data << std::endl;
    // std::cout << node->Data << std::endl;

    Node n;
    function(n);
    std::cout << n.Data << std::endl;

    // int* i = new int();
    // func1(i);
    // std ::cout << *i << std ::endl;
    return 0;
}