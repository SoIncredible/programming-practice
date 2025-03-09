#if defined _WIN32 || defined __CYGWIN__
#ifdef BUILDING_DLL
#ifdef __GNUC__
#define DLL_PUBLIC __attribute__((dllexport))
#else
#define DLL_PUBLIC __declspec(dllexport) // Note: actually gcc seems to also supports this syntax.
#endif
#else
#ifdef __GNUC__
#define DLL_PUBLIC __attribute__((dllimport))
#else
#define DLL_PUBLIC __declspec(dllimport) // Note: actually gcc seems to also supports this syntax.
#endif
#endif
#define DLL_LOCAL
#else
#if __GNUC__ >= 4
#define DLL_PUBLIC __attribute__((visibility("default")))
#define DLL_LOCAL __attribute__((visibility("hidden")))
#else
#define DLL_PUBLIC
#define DLL_LOCAL
#endif
#endif

template <typename T>
struct Node
{
    T *value;
    Node *next;
};

template <typename T>
class Stack{

private:
    Node<T> *_top;
    int _count;
public:
    Stack();
    ~Stack();
    void Push(T &data);
    T *Pop();
    T *Peek();
    bool IsEmpty();
    int Count();
};

template <typename T>
Stack<T>::Stack()
{
    _top = NULL;
    _count = 0;
}

template <typename T>
Stack<T>::~Stack()
{
    while (_top != NULL)
    {
        Node<T> *temp = _top;
        _top = _top->next;
        delete temp;
    }
}

template <typename T>
void Stack<T>::Push(T &data)
{
    Node<T> *node = new Node<T>();
    // 值传递 本体修改不会影响栈中的数据
    node->value = &data;
    node->next = _top;
    _top = node;
    _count++;
}

template <typename T>
T *Stack<T>::Pop()
{
    if (_top == NULL)
    {
        throw std::runtime_error("栈为空，无法进行 Peek 操作");
    }

    T *result = _top->value;
    Node<T> *oldTop = _top;
    _top = _top->next;
    _count--;
    delete oldTop;
    return result;
}

template <typename T>
T *Stack<T>::Peek()
{
    if (_top == NULL)
    {
        std::cout << "栈为空, 不能够Pop" << std::endl;
        throw std::runtime_error("栈为空，无法进行 Pop 操作");
    }
    return _top->value;
}

template <typename T>
bool Stack<T>::IsEmpty()
{
    return _count == 0;
}

template <typename T>
int Stack<T>::Count()
{
    return _count;
}
