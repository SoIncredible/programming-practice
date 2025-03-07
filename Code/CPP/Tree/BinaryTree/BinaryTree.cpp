#include"BinaryTree.h"
#include"StackLib.h"

template <typename T>
BinaryTree<T>::BinaryTree(){
    _root = nullptr;
}

template <typename T>
BinaryTree<T>::~BinaryTree()
{
}

template <typename T>
void BinaryTree<T>::AddNode()
{
    BinaryTreeNode *node = new BinaryTreeNode();

}
template <typename T>
void BinaryTree<T>::RemoveNode(){
    
}

template <typename T>
void BinaryTree<T>::LevelOrderTraversalIteration()
{
}

template <typename T>
void BinaryTree<T>::LevelOrderTraversalRecursion(){

}

template <typename T>
void BinaryTree<T>::PreorderTraversalIteration(){

}

// 递归遍历要点
// 1.确定递归函数的参数和返回值
// 2.确定终止条件
// 3.确定单层递归的逻辑
template <typename T>
Stack<BinaryTreeNode<T>> BinaryTree<T>::PreorderTraversalRecursion(){
    // 这里不该用Stack 该用队列的. Stack出栈的顺序正好和要遍历的顺序反了
    // 另外需要注意一点是 这里的Stack调用Pop接口时 会释放掉原来的内存 需要确认的是 这个删除是否会对原来的二叉树有影响?
    Stack<BinaryTreeNode<T>> *stack = new Stack<BinaryTreeNode<T>>();
    InnerPreorderTraversalRecursion(_root, stack);
    // while(
}

template <typename T>
void BinaryTree<T>::InorderTraversalIteration(){

}

template <typename T>
void BinaryTree<T>::InorderTraversalRecursion(){

}

template <typename T>
void BinaryTree<T>::PostorderTraversalIteration(){

}

template <typename T>
void BinaryTree<T>::PostorderTraversalRecursion(){

}

template <typename T>
void BinaryTree<T>::InnerLevelOrderTraversalIteration()
{
}

template <typename T>
void BinaryTree<T>::InnerLevelOrderTraversalRecursion(BinaryTreeNode<T> *cur)
{
   
}

template <typename T>
void BinaryTree<T>::InnerPreorderTraversalIteration(BinaryTreeNode<T> *cur, Stack<BinaryTreeNode<T>> *result)
{
  
}

template <typename T>
void BinaryTree<T>::InnerPreorderTraversalRecursion(BinaryTreeNode<T> *cur, Stack<BinaryTreeNode<T>> * stack)
{
    // 前序遍历 中->左->右
    if (cur == nullptr)
    {
        return;
    }

    // 输出cur的index
    stack->Push(cur)
    // 遍历左
    InnerPreorderTraversalRecursion(cur->left, stack);
    // 遍历右
    InnerPreorderTraversalRecursion(cur->right, stack);
}

template <typename T>
void BinaryTree<T>::InnerInorderTraversalIteration()
{
}

template <typename T>
void BinaryTree<T>::InnerInorderTraversalRecursion()
{
}

template <typename T>
void BinaryTree<T>::InnerPostorderTraversalIteration()
{
}

template <typename T>
void BinaryTree<T>::InnerPostorderTraversalRecursion()
{
}