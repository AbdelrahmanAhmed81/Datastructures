#include "../Includes/List.hpp"
#include <stdexcept>
#include <iostream>

List::List(int size)
{
    _size = size;
    _count = 0;
    _data = new int[size]{0};
}

List::List() : List::List(6)
{
}

int List::Size()
{
    return _size;
}

void List::Resize(int capacity)
{
    int newSize = _size + capacity;
    int *newData = new int[newSize];
    for (int i = 0; i < _size; i++)
    {
        newData[i] = _data[i];
    }
    _size = newSize;
    _data = newData;
}

int List::ElementAt(int index)
{
    if (IsValidIndex(index))
        return _data[index];
    else
        throw std::out_of_range("index out of list elements range");
}

int List::Count()
{
    return _count;
}

bool List::HasSpace(int minimumCapacity)
{
    return (_size - _count >= minimumCapacity);
}

bool List::IsValidIndex(int index)
{
    return (index >= 0 && index < _count);
}

int &List::operator[](int index)
{
    if (IsValidIndex(index))
        return _data[index];
    else
        throw std::out_of_range("index out of list elements range");
}

void List::Clear()
{
    List::RemoveRange(0, _count);
}

void List::Add(int element)
{
    List::AddAt(_count, element);
}

void List::AddAt(int index, int element)
{
    if (index < 0 || index > _count)
        throw std::out_of_range("index out of list elements range");

    if (!HasSpace(1))
        Resize(_resizeCapacity);

    if (index != _count)
    {
        List::Copy(_data, index, _data, index + 1, _count - index);
    }
    _data[index] = element;
    _count++;
}

void List::AddRange(int index, int *elements, int length)
{
    if (index < 0 || index > _count)
        throw std::out_of_range("index out of list elements range");

    if (!HasSpace(length))
        Resize((length < _resizeCapacity) ? _resizeCapacity : length);

    if (index != _count)
    {
        List::Copy(_data, index, _data, index + length, _count - index);
    }
    List::Copy(elements, 0, _data, index, length);
    _count += length;
}

void List::Remove()
{
    List::RemoveAt(_count - 1);
}

void List::RemoveAt(int index)
{
    if (!IsValidIndex(index))
        throw std::out_of_range("index out of list elements range");
    else
    {
        if (index != _count - 1)
        {
            List::Copy(_data, index + 1, _data, index, _count - (index + 1));
        }
        _count--;
    }
}

void List::RemoveRange(int index, int length)
{
    if (IsValidIndex(index) && index + length <= _count)
    {
        if (index + length != _count)
        {
            List::Copy(_data, index + length, _data, index, _count - (index + length));
        }

        _count -= length;
    }
    else
        throw std::out_of_range("invalid range");
}

void List::Copy(int *src, int srcIndex, int *dest, int destIndex, int length)
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

void List::Print()
{
    if (_count > 0)
    {
        for (int i = 0; i < _count; i++)
        {
            std::cout << _data[i] << ", ";
        }
    }
    else
    {
        std::cout << "Empty List";
    }
    std::cout << std::endl;
}
