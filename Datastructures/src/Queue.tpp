#include "../Includes/Queue.hpp"

#ifndef QUEUE_TPP
#define QUEUE_TPP

template <class T>
Queue<T>::Queue()
{
}

template <class T>
Queue<T>::~Queue()
{
    delete (_list);
}

template <class T>
void Queue<T>::Print()
{
    _list->Print();
}

template <class T>
int Queue<T>::Count()
{
    return _list->Count();
}

//O(1)
template <class T>
void Queue<T>::Enqueue(T value)
{
    _list->AddLast(value);
}

//O(1)
template <class T>
T Queue<T>::Peek()
{
    return _list->GetHeadValue();
}

//O(1)
template <class T>
T Queue<T>::Dequeue()
{
    T val = _list->GetHeadValue();
    _list->RemoveFirst();
    return val;
}

#endif