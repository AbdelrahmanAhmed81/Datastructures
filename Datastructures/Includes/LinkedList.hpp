template <class T>
class LinkedListNode
{
public:
    LinkedListNode(T value);
    T _value;
    LinkedListNode<T> *_next = nullptr;
    LinkedListNode<T> *_prev = nullptr;
};

template <class T>
class LinkedList
{
public:
    LinkedList();
    ~LinkedList();
    void AddLast(T value);
    void AddFirst(T value);
    void RemoveFirst();
    void RemoveLast();
    void AddNext(LinkedListNode<T> *node, T value);
    void AddBefore(LinkedListNode<T> *node, T value);
    LinkedListNode<T> *Find(T value);
    int Count();
    void Clear();
    void Print();
    bool IsEmpty();

private:
    int _count;
    void ResetHeadTail();
    LinkedListNode<T> *_head = nullptr;
    LinkedListNode<T> *_tail = nullptr;
};
