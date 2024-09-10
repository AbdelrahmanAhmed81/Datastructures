#include "../Includes/Stack.hpp"

#ifndef STACK_TPP
#define STACK_TPP

template <class T>
Stack<T>::Stack()
{
}

template <class T>
Stack<T>::~Stack()
{
    delete (_list);
}

template <class T>
void Stack<T>::Print()
{
    _list->Print();
}

template <class T>
int Stack<T>::Count()
{
    return _list->Count();
}

//O(1)
template <class T>
void Stack<T>::Push(T value)
{
    _list->AddLast(value);
}

//O(1)
template <class T>
T Stack<T>::Peek()
{
    return _list->GetTailValue();
}

//O(1)
template <class T>
T Stack<T>::Pop()
{
    T val = _list->GetTailValue();
    _list->RemoveLast();
    return val;
}

#endif