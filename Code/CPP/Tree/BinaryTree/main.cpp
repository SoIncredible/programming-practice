#include <iostream>
#include "BinaryTree.h"

int main(){

    //      5
    //     / \
    //    4   6
    //   / \
    //  2   1

    int a = 5;
    int b = 4;
    int c = 6;
    int d = 2;
    int e = 1;

    BinaryTreeNode<int> *head = new BinaryTreeNode<int>();
    head->data = &a;

    head->left = new BinaryTreeNode<int>();
    head->left->data = &b;

    head->right = new BinaryTreeNode<int>();
    head->right->data = &c;
    head->right->left = nullptr;
    head->right->right = nullptr;

    head->left->left = new BinaryTreeNode<int>();
    head->left->right = new BinaryTreeNode<int>();

    head->left->left->data = &d;
    head->left->left->left = nullptr;
    head->left->left->right = nullptr;

    head->left->right->data = &e;
    head->left->right->left = nullptr;
    head->left->right->right = nullptr;

    // 这个函数的析构函数被自动调用了,为什么?
    BinaryTree<int>* intBTree = new BinaryTree<int>(head);

    Queue<BinaryTreeNode<int>> *q = new Queue<BinaryTreeNode<int>>();
    // 前序遍历 递归
    // intBTree->PreorderTraversalRecursion(q);
    // 中序遍历 递归
    // intBTree->InorderTraversalRecursion(q);
    // 后序遍历 递归
    // intBTree->PostorderTraversalRecursion(q);
    // 前序遍历 迭代
    // intBTree->PreorderTraversalIteration(q);
    // 中序遍历 迭代
    // intBTree->InorderTraversalIteration(q);
    // 后序遍历 迭代
    // intBTree->PostorderTraversalIteration(q);
    // 层序遍历 迭代
    // intBTree->LevelOrderTraversalIteration(q);

    // 前序遍历 迭代 统一写法
    // intBTree->PreorderTraversalIterationUniform(q);

    // 中序遍历 迭代 统一写法
    // intBTree->InorderTraversalIterationUniform(q);

    // 后序遍历 迭代 统一写法
    intBTree->PostorderTraversalIterationUniform(q);

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
    // delete q; // 成员是QueueNode 删除的是指向BinaryTreeNode的指针和next指针
    // delete head->left->left;
    // delete head->left->right;
    // delete head->left;
    // delete head->right;
    // delete head;
#ifdef _WIN32
    delete intBTree;
#endif
    return 0;
}