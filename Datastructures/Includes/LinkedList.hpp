template <class T>
class LinkedListNode
{
public:
    LinkedListNode(T value);
    T _value;
    LinkedListNode<T> *_next = nullptr;
};

template <class T>
class LinkedList
{
public:
    LinkedList();
    void Add(T value);
    int Count();
    void Clear();
    void Print();
    bool IsEmpty();

private:
    int _count;
    LinkedListNode<T> *_head = nullptr;
    LinkedListNode<T> *_tail = nullptr;
};
