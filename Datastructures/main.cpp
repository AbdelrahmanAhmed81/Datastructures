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
    LinkedList<string> *linkedList = new LinkedList<string>();
    linkedList->AddLast("hello");
    linkedList->AddLast("world");
    linkedList->Print();

    LinkedListNode<string> *result_1 = linkedList->Find("world");
    if (result_1 != nullptr)
    {
        linkedList->AddNext(result_1, "!");
    }
    linkedList->Print();

    LinkedListNode<string> *result_2 = linkedList->Find("hello");
    if (result_2 != nullptr)
    {
        linkedList->AddBefore(result_2, ":)");
    }
    linkedList->Print();

    delete (result_1);
    delete (result_2);
    return 0;
}
