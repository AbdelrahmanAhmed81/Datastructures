#include "../src/LinkedList.tpp"

#ifndef STACK_HPP
#define STACK_HPP

template <class T>
class Stack
{
public:
    Stack();
    ~Stack();
    void Push(T value);
    T Pop();
    T Peek();
    int Count();
    void Print();

private:
    LinkedList<T> *_list = new LinkedList<T>();
};

#endif