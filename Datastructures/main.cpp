#include <iostream>
#include "src/ArrayList.tpp"
#include "src/LinkedList.tpp"
using namespace std;

int main()
{
    ////test ArrayList
    // ArrayList<string> *list = new ArrayList<string>();
    // string *arr = new string[3] {"hello","world","!"};
    // list->AddRange(0, arr, 3);
    // list->AddAt(1,"My");
    // list->Print();
    // delete(list);
    //-------------------------------------------------------
    // test LinkedList
    LinkedList<int> *linkedList = new LinkedList<int>();
    linkedList->Add(7);
    linkedList->Add(3);

    linkedList->Print();

    return 0;
}
