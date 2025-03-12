// #include "StackLib.h"
#include "QueueLib.h"

template <typename T>
struct BinaryTreeNode
{
    int index;             // 树节点的index
    T *data;               // 节点存储的数据
    BinaryTreeNode<T> *left;  // 左子树
    BinaryTreeNode<T> *right; // 右子树
};

template <typename T>
class BinaryTree
{
private:
    BinaryTreeNode<T> *_root;

    void InnerLevelOrderTraversalIteration();

    void InnerLevelOrderTraversalRecursion(BinaryTreeNode<T> *cur);

    void InnerPreorderTraversalIteration(BinaryTreeNode<T> *cur, Queue<BinaryTreeNode<T> > *stack);

    void InnerPreorderTraversalRecursion(BinaryTreeNode<T> &cur, Queue<BinaryTreeNode<T> > *stack);

    void InnerInorderTraversalIteration();

    void InnerInorderTraversalRecursion();

    void InnerPostorderTraversalIteration();

    void InnerPostorderTraversalRecursion();

public:

    BinaryTree();

    BinaryTree(BinaryTreeNode<T> *node);

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
    Queue<BinaryTreeNode<T> > *PreorderTraversalRecursion();

    // 中序遍历-深度优先-迭代
    void InorderTraversalIteration();

    // 中序遍历-深度优先-递归
    void InorderTraversalRecursion();

    // 后序遍历-深度优先-迭代
    void PostorderTraversalIteration();

    // 后序遍历-深度优先-递归
    void PostorderTraversalRecursion();
};

template <typename T>
BinaryTree<T>::BinaryTree()
{
    _root = nullptr;
}

template <typename T>
BinaryTree<T>::BinaryTree(BinaryTreeNode<T> *node)
{
    _root = node;
}

template <typename T>
BinaryTree<T>::~BinaryTree()
{
}

template <typename T>
void BinaryTree<T>::AddNode()
{
    BinaryTreeNode<T> *node = new BinaryTreeNode<T>();
}
template <typename T>
void BinaryTree<T>::RemoveNode()
{
}

template <typename T>
void BinaryTree<T>::LevelOrderTraversalIteration()
{
}

template <typename T>
void BinaryTree<T>::LevelOrderTraversalRecursion()
{
}

template <typename T>
void BinaryTree<T>::PreorderTraversalIteration()
{
}

// 递归遍历要点
// 1.确定递归函数的参数和返回值
// 2.确定终止条件
// 3.确定单层递归的逻辑
template <typename T>
Queue<BinaryTreeNode<T> > *BinaryTree<T>::PreorderTraversalRecursion()
{
    // 这里不该用Stack 该用队列的. Stack出栈的顺序正好和要遍历的顺序反了
    // 另外需要注意一点是 这里的Stack调用Pop接口时 会释放掉原来的内存 需要确认的是 这个删除是否会对原来的二叉树有影响?
    Queue<BinaryTreeNode<T> > *queue = new Queue<BinaryTreeNode<T> >();
    InnerPreorderTraversalRecursion(_root, queue);
    return queue;
}

template <typename T>
void BinaryTree<T>::InorderTraversalIteration()
{
}

template <typename T>
void BinaryTree<T>::InorderTraversalRecursion()
{
}

template <typename T>
void BinaryTree<T>::PostorderTraversalIteration()
{
}

template <typename T>
void BinaryTree<T>::PostorderTraversalRecursion()
{
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
void BinaryTree<T>::InnerPreorderTraversalIteration(BinaryTreeNode<T> *cur, Queue<BinaryTreeNode<T> > *result)
{
}

template <typename T>
void BinaryTree<T>::InnerPreorderTraversalRecursion(BinaryTreeNode<T> &cur, Queue<BinaryTreeNode<T> > *queue)
{
    // 前序遍历 中->左->右
    if (cur == nullptr)
    {
        return;
    }

    // 输出cur的index
    queue->EnQueue(cur);
    // 遍历左
    InnerPreorderTraversalRecursion(cur->left, queue);
    // 遍历右
    InnerPreorderTraversalRecursion(cur->right, queue);
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