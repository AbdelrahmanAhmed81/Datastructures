#include "../src/LinkedList.tpp"

#ifndef QUEUE_HPP
#define QUEUE_HPP

template <class T>
class Queue
{
public:
    Queue();
    ~Queue();
    void Enqueue(T value);
    T Dequeue();
    T Peek();
    int Count();
    void Print();

private:
    LinkedList<T> *_list = new LinkedList<T>();
};

#endif