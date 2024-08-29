#include "../Includes/ArrayList.hpp"
#include <stdexcept>
#include <iostream>

template <class T>
ArrayList<T>::ArrayList()
{
    _size = _initCapacity;
    _count = 0;
    _data = new T[_initCapacity];
}

template <class T>
int ArrayList<T>::Size()
{
    return _size;
}

template <class T>
void ArrayList<T>::Resize(int capacity)
{
    int newSize = _size + capacity;
    T *newData = new T[newSize];
    for (int i = 0; i < _size; i++)
    {
        newData[i] = _data[i];
    }
    _size = newSize;
    _data = newData;
}

template <class T>
T ArrayList<T>::ElementAt(int index)
{
    if (IsValidIndex(index))
        return _data[index];
    else
        throw std::out_of_range("index out of list elements range");
}

template <class T>
int ArrayList<T>::Count()
{
    return _count;
}

template <class T>
bool ArrayList<T>::HasSpace(int minimumCapacity)
{
    return (_size - _count >= minimumCapacity);
}

template <class T>
bool ArrayList<T>::IsValidIndex(int index)
{
    return (index >= 0 && index < _count);
}

template <class T>
T &ArrayList<T>::operator[](int index)
{
    if (IsValidIndex(index))
        return _data[index];
    else
        throw std::out_of_range("index out of list elements range");
}

template <class T>
void ArrayList<T>::Clear()
{
    ArrayList::RemoveRange(0, _count);
}

template <class T>
void ArrayList<T>::Add(T element)
{
    ArrayList::AddAt(_count, element);
}

template <class T>
void ArrayList<T>::AddAt(int index, T element)
{
    if (index < 0 || index > _count)
        throw std::out_of_range("index out of list elements range");

    if (!HasSpace(1))
        Resize(_resizeCapacity);

    if (index != _count)
    {
        ArrayList::Copy(_data, index, _data, index + 1, _count - index);
    }
    _data[index] = element;
    _count++;
}

template <class T>
void ArrayList<T>::AddRange(int index, T *elements, int length)
{
    if (index < 0 || index > _count)
        throw std::out_of_range("index out of list elements range");

    if (!HasSpace(length))
        Resize((length < _resizeCapacity) ? _resizeCapacity : length);

    if (index != _count)
    {
        ArrayList::Copy(_data, index, _data, index + length, _count - index);
    }
    ArrayList::Copy(elements, 0, _data, index, length);
    _count += length;
}

template <class T>
void ArrayList<T>::Remove()
{
    ArrayList::RemoveAt(_count - 1);
}

template <class T>
void ArrayList<T>::RemoveAt(int index)
{
    if (!IsValidIndex(index))
        throw std::out_of_range("index out of list elements range");
    else
    {
        if (index != _count - 1)
        {
            ArrayList::Copy(_data, index + 1, _data, index, _count - (index + 1));
        }
        _count--;
    }
}

template <class T>
void ArrayList<T>::RemoveRange(int index, int length)
{
    if (IsValidIndex(index) && index + length <= _count)
    {
        if (index + length != _count)
        {
            ArrayList::Copy(_data, index + length, _data, index, _count - (index + length));
        }

        _count -= length;
    }
    else
        throw std::out_of_range("invalid range");
}

template <class T>
void ArrayList<T>::Copy(T *src, int srcIndex, T *dest, int destIndex, int length)
{
    if (srcIndex >= destIndex)
    {
        for (int i = srcIndex, j = destIndex; length > 0; i++, j++, length--)
        {
            dest[j] = src[i];
        }
    }
    else
    {
        for (int i = srcIndex + length - 1, j = destIndex + length - 1; length > 0; i--, j--, length--)
        {
            dest[j] = src[i];
        }
    }
}

template <class T>
void ArrayList<T>::Print()
{
    if (_count <= 0)
        std::cout << "Empty List";
    else
    {
        for (int i = 0; i < _count; i++)
        {
            std::cout << _data[i] << ' ';
        }
    }

    std::cout << std::endl;
}
