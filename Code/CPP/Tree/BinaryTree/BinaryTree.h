#include "StackLib.h"

template <typename T>
struct BinaryTreeNode
{
    int index;             // 树节点的index
    T *data;               // 节点存储的数据
    BinaryTreeNode *left;  // 左子树
    BinaryTreeNode *right; // 右子树
};

template <typename T>
class BinaryTree
{
private:
    BinaryTreeNode *_root;

    void InnerLevelOrderTraversalIteration();

    void InnerLevelOrderTraversalRecursion(BinaryTreeNode<T> *cur);

    void InnerPreorderTraversalIteration(BinaryTreeNode<T> *cur, Stack<BinaryTreeNode<T>> *stack);

    void InnerPreorderTraversalRecursion(BinaryTreeNode<T> *cur, Stack<BinaryTreeNode<T>> *stack);

    void InnerInorderTraversalIteration();

    void InnerInorderTraversalRecursion();

    void InnerPostorderTraversalIteration();

    void InnerPostorderTraversalRecursion();

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
    Stack<BinaryTreeNode<T>> PreorderTraversalRecursion();

    // 中序遍历-深度优先-迭代
    void InorderTraversalIteration();

    // 中序遍历-深度优先-递归
    void InorderTraversalRecursion();

    // 后序遍历-深度优先-迭代
    void PostorderTraversalIteration();

    // 后序遍历-深度优先-递归
    void PostorderTraversalRecursion();
};