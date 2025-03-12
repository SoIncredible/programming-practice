#include <iostream>
#include "BinaryTree.h"

int main(){

    BinaryTreeNode<int> *head = new BinaryTreeNode<int>();

    head->data = new int(1);

    head->left = new BinaryTreeNode<int>();
    head->left->data = new int(2);
    head->left->left = nullptr;
    head->left->right = nullptr;

    head->right = new BinaryTreeNode<int>();

    head->right->data = new int(3);
    head->right->left = nullptr;
    head->right->right = nullptr;

    BinaryTree<int>* intBTree = new BinaryTree<int>(head);

    Queue<BinaryTreeNode<int> > *q = intBTree->PreorderTraversalRecursion();

    while(!q->IsEmpty()){
        BinaryTreeNode<int> *qq = q->DeQueue();
        std::cout << qq->data << std::endl;
    }

    delete head->left;
    delete head->right;
    delete head;
    return 0;
}