template <class T>
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
    T ElementAt(int index);
    /// get element value in a specific index
    T &operator[](int index);
    /// get the capacity of the list
    int Size();
    /// clear the list
    void Clear();
    /// add element at the end of the list
    void Add(T element);
    /// add element at a specific index
    void AddAt(int index, T element);
    /// add range of elements starting from a specific indexs
    void AddRange(int index, T *elements, int length);
    /// removes the last element
    void Remove();
    /// removes element at a specific index
    void RemoveAt(int index);
    /// removes range of elements starting from a specifiic index
    void RemoveRange(int index, int length);
    /// prints all list items
    void Print();

private:
    const int _resizeCapacity = 4;
    int _size;
    int _count;
    T *_data;
    bool HasSpace(int minimumCapacity);
    bool IsValidIndex(int index);
    void Resize(int capacity);
    void static Copy(T *src, int srcIndex, T *dest, int destIndex, int length);
};