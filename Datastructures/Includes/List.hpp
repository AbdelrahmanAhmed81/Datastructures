#ifndef LIST_HPP_INCLUDED
#define LIST_HPP_INCLUDED

class List
{
public:
    /// create a list with a specific size
    List(int size);
    /// create a list with the default size [default = 6]
    List();
    /// get the number of the items in the list
    int Count();
    /// get element value in a specific index
    int ElementAt(int index);
    /// get element value in a specific index
    int &operator[](int index);
    /// get the capacity of the list
    int Size();
    /// clear the list
    void Clear();
    /// add element to the list
    void Add(int element);
    /// add element at a specific index
    void AddAt(int index, int element);
    /// add range of elements starting from a specific indexs
    void AddRange(int index, int *elements, int length);
    /// removes the last element
    void Remove();
    /// removes element at a specific index
    void RemoveAt(int index);
    /// removes range of elements starting from a specifiic index
    void RemoveRange(int index, int length);
    /// prints all list items
    void Print();

private:
    int _size;
    int _count;
    int *_data;
    const int _resizeCapacity = 4;
    bool HasSpace(int minimumCapacity);
    bool IsValidIndex(int index);
    void Resize(int capacity);
    void static Copy(int *src, int srcIndex, int *dest, int destIndex, int length);
};

#endif
