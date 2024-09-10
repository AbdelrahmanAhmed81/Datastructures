#ifndef ARRAYLIST_HPP
#define ARRAYLIST_HPP

template <class T>
class ArrayList
{
public:
    ArrayList();
    int Count();
    T ElementAt(int index);
    T &operator[](int index);
    int Size();
    void Clear();
    void Add(T element);
    void AddAt(int index, T element);
    void AddRange(int index, T *elements, int length);
    void Remove();
    void RemoveAt(int index);
    void RemoveRange(int index, int length);
    void Print();

private:
    const int _resizeCapacity = 4;
    const int _initCapacity = 6;
    int _size;
    int _count;
    T *_data;
    bool HasSpace(int minimumCapacity);
    bool IsValidIndex(int index);
    void Resize(int capacity);
    void static Copy(T *src, int srcIndex, T *dest, int destIndex, int length);
};

#endif