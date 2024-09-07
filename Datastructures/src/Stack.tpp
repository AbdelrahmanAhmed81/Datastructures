#include "../Includes/Stack.hpp"

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
    return _list->Count;
}

template <class T>
void Stack<T>::Push(T value)
{
    _list->AddLast(value);
}

template <class T>
T Stack<T>::Peek()
{
    return _list->GetTailValue();
}

template <class T>
T Stack<T>::Pop()
{
    T val = _list->GetTailValue();
    _list->RemoveLast();
    return val;
}
