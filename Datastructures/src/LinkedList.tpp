#include <iostream>
#include "../Includes/LinkedList.hpp"

using namespace std;

template <class T>
LinkedListNode<T>::LinkedListNode(T value)
{
    _value = value;
    _next = nullptr;
    _prev = nullptr;
}

template <class T>
LinkedList<T>::LinkedList()
{
    _count = 0;
}

template <class T>
LinkedList<T>::~LinkedList()
{
    LinkedList<T>::Clear();
}

template <class T>
int LinkedList<T>::Count()
{
    return _count;
}

template <class T>
void LinkedList<T>::Clear()
{
    while (_tail->_prev != nullptr)
    {
        _tail = _tail->_prev;
        delete (_tail->_next);
    }
    delete (_tail);
    ResetHeadTail();
    _count = 0;
}

template <class T>
bool LinkedList<T>::IsEmpty()
{
    return _count == 0;
}

template <class T>
void LinkedList<T>::AddLast(T value)
{
    if (LinkedList::IsEmpty())
    {
        _head = _tail = new LinkedListNode<T>(value);
    }
    else
    {
        _tail->_next = new LinkedListNode<T>(value);
        _tail->_next->_prev = _tail;
        _tail = _tail->_next;
    }
    _count++;
}

template <class T>
void LinkedList<T>::AddFirst(T value)
{
    if (LinkedList::IsEmpty())
    {
        _head = _tail = new LinkedListNode<T>(value);
    }
    else
    {
        _head->_prev = new LinkedListNode<T>(value);
        _head->_prev->_next = _head;
        _head = _head->_prev;
    }
    _count++;
}

template <class T>
void LinkedList<T>::Print()
{
    if (LinkedList::IsEmpty())
        std::cout << "Empty List" << endl;
    else
    {
        LinkedListNode<T> *current = _head;
        while (current != nullptr)
        {
            cout << current->_value << " ";
            current = current->_next;
        }
        cout << endl;
        delete (current);
    }
}

template <class T>
void LinkedList<T>::RemoveFirst()
{
    if (_count == 1)
    {
        delete (_head);
        ResetHeadTail();
    }
    else
    {
        _head = _head->_next;
        delete (_head->_prev);
        _head->_prev = nullptr;
    }
    _count--;
}

template <class T>
void LinkedList<T>::RemoveLast()
{
    if (_count == 1)
    {
        delete (_tail);
        ResetHeadTail();
    }
    else
    {
        _tail = _tail->_prev;
        delete (_tail->_next);
        _tail->_next = nullptr;
    }
    _count--;
}

template <class T>
LinkedListNode<T> *LinkedList<T>::Find(T value)
{
    if (IsEmpty())
        return nullptr;

    for (LinkedListNode<T> *current = _head; current != nullptr; current = current->_next)
    {
        if (current->_value == value)
            return current;
    }

    return nullptr;
}

template <class T>
void LinkedList<T>::AddNext(LinkedListNode<T> *node, T value)
{
    if (node == nullptr)
        return;

    if (node == _tail)
    {
        AddLast(value);
    }
    else
    {
        LinkedListNode<T> *newNode = new LinkedListNode<T>(value);

        newNode->_prev = node;
        newNode->_next = node->_next;
        node->_next = newNode;
        newNode->_next->_prev = newNode;
    }
}

template <class T>
void LinkedList<T>::AddBefore(LinkedListNode<T> *node, T value)
{
    if (node == nullptr)
        return;

    if (node == _head)
    {
        AddFirst(value);
    }
    else
    {
        LinkedListNode<T> *newNode = new LinkedListNode<T>(value);

        newNode->_next = node;
        newNode->_prev = node->_prev;
        node->_prev = newNode;
        newNode->_prev->_next = newNode;
    }
}

template <class T>
T LinkedList<T>::GetTailValue()
{
    return _tail->_value;
}

template <class T>
T LinkedList<T>::GetHeadValue()
{
    return _head->_value;
}

template <class T>
void LinkedList<T>::ResetHeadTail()
{
    _head = _tail = nullptr;
}
