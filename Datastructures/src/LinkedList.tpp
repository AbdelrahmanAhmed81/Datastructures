#include <iostream>
#include "../Includes/LinkedList.hpp"

using namespace std;

template <class T>
LinkedListNode<T>::LinkedListNode(T value)
{
    LinkedListNode::_value = value;
    LinkedListNode::_next = nullptr;
}

template <class T>
LinkedList<T>::LinkedList()
{
    LinkedList::_count = 0;
}

template <class T>
int LinkedList<T>::Count()
{
    return LinkedList::_count;
}

template <class T>
bool LinkedList<T>::IsEmpty()
{
    return LinkedList::_count == 0;
}

template <class T>
void LinkedList<T>::Add(T value)
{
    if (LinkedList::IsEmpty())
    {
        LinkedList::_head = LinkedList::_tail = new LinkedListNode<T>(value);
    }
    else
    {
        LinkedList::_tail->_next = new LinkedListNode<T>(value);
        LinkedList::_tail = LinkedList::_tail->_next;
    }
    LinkedList::_count++;
}

template <class T>
void LinkedList<T>::Print()
{
    if (LinkedList::IsEmpty())
        std::cout << "Empty List";
    else
    {
        LinkedListNode<T> *current = LinkedList::_head;
        while (current != nullptr)
        {
            cout << current->_value << endl;

            current = current->_next;
        }

        delete (current);
    }
}