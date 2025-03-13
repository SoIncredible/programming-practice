#include <iostream>
#include "BinaryTreePtr.h"
#include "BinaryTreeRef.h"

int main(){

    BinaryTreeNode<int> *head = new BinaryTreeNode<int>();

    int a = 1;
    head->data = &a;

    a = 666;

    head->left = new BinaryTreeNode<int>();
    // int *a = new int(2);
    int b = 2;
    head->left->data = &b;
    head->left->left = nullptr;
    head->left->right = nullptr;

    head->right = new BinaryTreeNode<int>();

    int c = 3;
    head->right->data = &c;
    head->right->left = nullptr;
    head->right->right = nullptr;

    BinaryTree<int>* intBTree = new BinaryTree<int>(head);

    // Queue<BinaryTreeNode<int> > *q = intBTree->PreorderTraversalRecursion();

    Queue<BinaryTreeNode<int> > *q = new Queue<BinaryTreeNode<int> >();
    // intBTree->InorderTraversalRecursion(q);
    intBTree->PostorderTraversalRecursion(q);

    // 这种方式创建的指针是不需要delete的 函数作用域结束之后内存会自动被回收
    BinaryTree<int> intBTreeOnStack = BinaryTree<int>(head);
    BinaryTree<int> *intBTreeOnStackPtr = &intBTreeOnStack;
    //
    
    while(!q->IsEmpty()){
        // 通过接收函数返回值的方式得到创建的字段，如果函数的返回值不是new出来的，那么这个字段就不需要delete
        BinaryTreeNode<int> *qq = q->DeQueue();
        std::cout << qq->GetData() << std::endl;
    }

    // TODO Eddie 需要明确这些delete操作各自删除了什么？
    delete q; // 成员是QueueNode 删除的是指向BinaryTreeNode的指针和next指针
    delete head->left;
    delete head->right;
    delete head;
    delete intBTree;
    return 0;
}