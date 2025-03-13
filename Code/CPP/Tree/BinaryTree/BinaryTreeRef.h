#include "QueueLib.h"

/// 该脚本为二叉树的引用版本 树的信息存储基于引用

template <typename T>
struct BinaryTreeNode
{
    T &data;
    BinaryTreeNode &left;
    BinaryTreeNode &right;
};

template <typename T>
class BinaryTree
{
private:
    BinaryTreeNode<T> _root;

    void InnerLevelOrderTraversalIteration();

    void InnerLevelOrderTraversalRecursion(BinaryTreeNode<T> &cur);

    void InnerPreorderTraversalIteration(BinaryTreeNode<T> &cur, Queue<BinaryTreeNode<T> > &queue);

    void InnerPreorderTraversalRecursion(BinaryTreeNode<T> &cur, Queue<BinaryTreeNode<T> > &queue);

    void InnerInorderTraversalIteration();

    void InnerInorderTraversalRecursion(BinaryTreeNode<T> &cur, Queue<BinaryTreeNode<T> > &queue);

    void InnerPostorderTraversalIteration();

    void InnerPostorderTraversalRecursion(BinaryTreeNode<T> &cur, Queue<BinaryTreeNode<T> > &queue);    

public:
    BinaryTree();
    ~BinaryTree();

     // 增加节点
     void AddNode();

     // 删除节点
     void RemoveNode();
 
     // 层序遍历-广度优先-迭代
     void LevelOrderTraversalIteration();
 
     // 层序遍历-广度优先-递归
     void LevelOrderTraversalRecursion();
 
     // 前序遍历-深度优先-迭代
     void PreorderTraversalIteration();
 
     // 前序遍历-深度优先-递归
     void PreorderTraversalRecursion(Queue<BinaryTreeNode<T> > &queue);
 
     // 中序遍历-深度优先-迭代
     void InorderTraversalIteration();
 
     // 中序遍历-深度优先-递归
     void InorderTraversalRecursion(Queue<BinaryTreeNode<T> > *queue);
 
     // 后序遍历-深度优先-迭代
     void PostorderTraversalIteration();
 
     // 后序遍历-深度优先-递归
     void PostorderTraversalRecursion(Queue<BinaryTreeNode<T> > *queue);

};

template <typename T>
BinaryTree<T>::BinaryTree()
{
}

template <typename T>
BinaryTree<T>::~BinaryTree()
{
}

