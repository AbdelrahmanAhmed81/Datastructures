#include <iostream>
#include "Includes/List.hpp"
using namespace std;

int main()
{
    List list(3);
    list.Add(5);
    list.Add(2);
    list.Add(1);
    list.Print();
    list.AddAt(3, 4);
    list.Print();

    int *arr = new int[3]{6, 7, 8};
    list.AddRange(1, arr, 3);
    list.Print();
    return 0;
}
