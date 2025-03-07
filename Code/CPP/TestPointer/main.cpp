
#include<iostream>

struct Node{
    int Data;
    Node *next;
};

int main(){

    Node node = Node();
    node.Data = 2;
    node.next = nullptr;
    Node *origin = &node;

    Node *another = origin;

    std::cout << origin->Data << std::endl;
    std::cout << another->Data << std::endl;

   another = nullptr;

    std::cout << origin->Data << std::endl;
    std::cout << node.Data << std::endl;
    return 0;
}