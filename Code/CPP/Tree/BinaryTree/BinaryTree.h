#include "QueueLib.h"
#include "StackLib.h"

/// 该脚本为二叉树的指针版本 树的信息存储基于指针

template <typename T>
struct BinaryTreeNode
{
    int index;             // 树节点的index
    T *data;               // 节点存储的数据
    BinaryTreeNode<T> *left;  // 左子树
    BinaryTreeNode<T> *right; // 右子树

    void SetData(T &d){
        data = &data;
    }

    void SetData(T *d){
        data = d;
    }

    T GetData(){
        return *data;
    }
};

template <typename T>
class BinaryTree
{
private:
    BinaryTreeNode<T> *_root;

    void InnerLevelOrderTraversalIteration();

    void InnerLevelOrderTraversalRecursion(BinaryTreeNode<T> *cur);

    void InnerPreorderTraversalIteration(BinaryTreeNode<T> *cur, Queue<BinaryTreeNode<T> > *stack);

    void InnerPreorderTraversalRecursion(BinaryTreeNode<T> *cur, Queue<BinaryTreeNode<T> > *stack);

    void InnerInorderTraversalIteration();

    void InnerInorderTraversalRecursion(BinaryTreeNode<T> *cur, Queue<BinaryTreeNode<T>  > *queue);

    void InnerPostorderTraversalIteration();

    void InnerPostorderTraversalRecursion(BinaryTreeNode<T> *cur, Queue<BinaryTreeNode<T> > *queue);

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
    void PreorderTraversalIteration(Queue< BinaryTreeNode<T> > *queue);

    // 前序遍历-深度优先-递归
    void PreorderTraversalRecursion(Queue< BinaryTreeNode<T> > *queue);

    // 中序遍历-深度优先-迭代
    void InorderTraversalIteration();

    // 中序遍历-深度优先-递归
    void InorderTraversalRecursion(Queue< BinaryTreeNode<T> > *queue);

    // 后序遍历-深度优先-迭代
    void PostorderTraversalIteration();

    // 后序遍历-深度优先-递归
    void PostorderTraversalRecursion(Queue< BinaryTreeNode<T> > *queue);
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
    // TODO Eddie 删除树中的所有节点
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
void BinaryTree<T>::PreorderTraversalIteration(Queue< BinaryTreeNode<T> > *queue)
{
    Stack< BinaryTreeNode<T> > stack = Stack< BinaryTreeNode<T> >();

    stack.Push(_root);
    
    while(!stack.IsEmpty()){
        BinaryTreeNode<T> *node = stack.Pop();
        queue->EnQueue(node);
        if (node->right != nullptr)
        {
            stack.Push(node->right);
        }
        if(node->left != nullptr){
            stack.Push(node->left);
        }
    }
}

// 递归遍历要点
// 1.确定递归函数的参数和返回值
// 2.确定终止条件
// 3.确定单层递归的逻辑
template <typename T>
void BinaryTree<T>::PreorderTraversalRecursion(Queue<BinaryTreeNode<T> > *queue)
{
    // 在使用C++时，当向一个方法请求返回一组数据结构时，最好的做法是调用这个方法，并向这个方法中传入用来存储结果的指针
    // 因为这样能确保这个指针的new和delete是成对出现的
    // 如果你在这个方法内部new了一个队列 然后返回出去 外部很有可能在完成操作后忘记对这个队列执行delete操作，这就造成内存泄漏了
    InnerPreorderTraversalRecursion(_root, queue);
}

template <typename T>
void BinaryTree<T>::InorderTraversalIteration()
{
}

// 中序遍历
template <typename T>
void BinaryTree<T>::InorderTraversalRecursion(Queue<BinaryTreeNode<T> > *queue)
{
    InnerInorderTraversalRecursion(_root, queue);
}

template <typename T>
void BinaryTree<T>::PostorderTraversalIteration()
{
}

template <typename T>
void BinaryTree<T>::PostorderTraversalRecursion(Queue<BinaryTreeNode<T> > *queue)
{
    InnerPostorderTraversalRecursion(_root, queue);
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
void BinaryTree<T>::InnerPreorderTraversalRecursion(BinaryTreeNode<T> *cur, Queue<BinaryTreeNode<T> > *queue)
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
void BinaryTree<T>::InnerInorderTraversalRecursion(BinaryTreeNode<T> *cur, Queue<BinaryTreeNode<T> > *queue)
{
    // 前序遍历 中->左->右
    if (cur == nullptr)
    {
        return;
    }

    // 遍历左
    InnerPreorderTraversalRecursion(cur->left, queue);

    // 输出cur的index
    queue->EnQueue(cur);

    // 遍历右
    InnerPreorderTraversalRecursion(cur->right, queue);
}

template <typename T>
void BinaryTree<T>::InnerPostorderTraversalIteration()
{
}

template <typename T>
void BinaryTree<T>::InnerPostorderTraversalRecursion(BinaryTreeNode<T> *cur, Queue<BinaryTreeNode<T> > *queue)
{
    // 前序遍历 中->左->右
    if (cur == nullptr)
    {
        return;
    }

    // 遍历左
    InnerPreorderTraversalRecursion(cur->left, queue);

    // 遍历右
    InnerPreorderTraversalRecursion(cur->right, queue);

     // 输出cur的index
     queue->EnQueue(cur);
}