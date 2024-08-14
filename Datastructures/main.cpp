#include <iostream>
#include "src/List.tpp"
using namespace std;

int main()
{
    List<string> list(3);
    string *arr = new string[3] {"hello","world","!"};
    list.AddRange(0, arr, 3);
    list.Print();
    return 0;
}
