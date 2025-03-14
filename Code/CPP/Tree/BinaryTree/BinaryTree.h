#ifndef QUEUELIB_H
#include "QueueLib.h"
#define QUEUELIB_H
#endif

#ifndef STACKLIB_H
#include "StackLib.h"
#define STACKLIB_H
#endif

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

    void InnerPreorderTraversalRecursion(BinaryTreeNode<T> *cur, Queue<BinaryTreeNode<T>> *stack);

    void InnerInorderTraversalRecursion(BinaryTreeNode<T> *cur, Queue<BinaryTreeNode<T>> *queue);

    void InnerPostorderTraversalRecursion(BinaryTreeNode<T> *cur, Queue<BinaryTreeNode<T>> *queue);

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
    void PreorderTraversalIteration(Queue<BinaryTreeNode<T>> *queue);

    // 前序遍历-深度优先-递归
    void PreorderTraversalRecursion(Queue<BinaryTreeNode<T>> *queue);

    // 中序遍历-深度优先-迭代
    void InorderTraversalIteration(Queue<BinaryTreeNode<T>> *queue);

    // 中序遍历-深度优先-递归
    void InorderTraversalRecursion(Queue<BinaryTreeNode<T>> *queue);

    // 后序遍历-深度优先-迭代
    void PostorderTraversalIteration(Queue<BinaryTreeNode<T>> *queue);

    // 后序遍历-深度优先-递归
    void PostorderTraversalRecursion(Queue<BinaryTreeNode<T>> *queue);
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
    // 前序遍历所有节点
    Queue<BinaryTreeNode<T>> *queue = new Queue<BinaryTreeNode<T>>();
    PreorderTraversalRecursion(queue);
    while(!queue->IsEmpty()){
        BinaryTreeNode<T>* node = queue->DeQueue();
        delete node;
    }
    delete queue;
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

/// @brief 迭代方式前序遍历二叉树
/// @tparam T 
/// @param queue 
template <typename T>
void BinaryTree<T>::PreorderTraversalIteration(Queue<BinaryTreeNode<T>> *queue)
{
    Stack<BinaryTreeNode<T>> stack = Stack<BinaryTreeNode<T>>();

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
void BinaryTree<T>::PreorderTraversalRecursion(Queue<BinaryTreeNode<T>> *queue)
{
    // 在使用C++时，当向一个方法请求返回一组数据结构时，最好的做法是调用这个方法，并向这个方法中传入用来存储结果的指针
    // 因为这样能确保这个指针的new和delete是成对出现的
    // 如果你在这个方法内部new了一个队列 然后返回出去 外部很有可能在完成操作后忘记对这个队列执行delete操作，这就造成内存泄漏了
    InnerPreorderTraversalRecursion(_root, queue);
}

template <typename T>
void BinaryTree<T>::InorderTraversalIteration(Queue<BinaryTreeNode<T>> *queue)
{
    // 迭代方式 中序遍历二叉树结点
    BinaryTreeNode<T> *cur = _root;
    Stack<BinaryTreeNode<T>> stack = Stack<BinaryTreeNode<T>>();
    
    while(cur != nullptr || !stack.IsEmpty()){
        if(cur != nullptr){ // 如果当前节点不为null
            stack.Push(cur); // 将当前节点入栈
            cur = cur->left; // 尝试遍历当前节点的左孩子节点
        }else{ // 如果当前节点是空了
            BinaryTreeNode<T> *node = stack.Pop(); // 从栈中取出来一个元素
            queue->EnQueue(node); // 将该元素放入返回队列中
            cur = node->right; // 尝试遍历取出来的这个元素的右孩子
        }
    }
}

// 中序遍历
template <typename T>
void BinaryTree<T>::InorderTraversalRecursion(Queue<BinaryTreeNode<T>> *queue)
{
    InnerInorderTraversalRecursion(_root, queue);
}

template <typename T>
void BinaryTree<T>::PostorderTraversalIteration(Queue<BinaryTreeNode<T>> *queue)
{
    Stack<BinaryTreeNode<T>> stack = Stack<BinaryTreeNode<T>>();

    stack.Push(_root);
    
    // 而后续遍历的顺序是左 -> 右 -> 中 需要将队列翻转一下
    while(!stack.IsEmpty()){
        BinaryTreeNode<T> *node = stack.Pop();
        queue->EnQueue(node);
        if(node->left != nullptr){
            stack.Push(node->left);
        }
        if (node->right != nullptr)
        {
            stack.Push(node->right);
        }
    }

    // 将队列反转

    queue->Reverse();

    // while(!queue->IsEmpty()){
    //     BinaryTreeNode<T> *node = queue->DeQueue();
    //     stack.Push(node);
    // }

    // while(!stack.IsEmpty()){
    //     BinaryTreeNode<T> *node = stack.Pop();
    //     queue->EnQueue(node);
    // }
}

template <typename T>
void BinaryTree<T>::PostorderTraversalRecursion(Queue<BinaryTreeNode<T>> *queue)
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
void BinaryTree<T>::InnerPreorderTraversalRecursion(BinaryTreeNode<T> *cur, Queue<BinaryTreeNode<T>> *queue)
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
void BinaryTree<T>::InnerInorderTraversalRecursion(BinaryTreeNode<T> *cur, Queue<BinaryTreeNode<T>> *queue)
{
    // 前序遍历 中->左->右
    if (cur == nullptr)
    {
        return;
    }

    // 遍历左
    InnerInorderTraversalRecursion(cur->left, queue);

    // 输出cur的index
    queue->EnQueue(cur);

    // 遍历右
    InnerInorderTraversalRecursion(cur->right, queue);
}

template <typename T>
void BinaryTree<T>::InnerPostorderTraversalRecursion(BinaryTreeNode<T> *cur, Queue<BinaryTreeNode<T>> *queue)
{
    // 前序遍历 中->左->右
    if (cur == nullptr)
    {
        return;
    }

    // 遍历左
    InnerPostorderTraversalRecursion(cur->left, queue);

    // 遍历右
    InnerPostorderTraversalRecursion(cur->right, queue);

     // 输出cur的index
     queue->EnQueue(cur);
}