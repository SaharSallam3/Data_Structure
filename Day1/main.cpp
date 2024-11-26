#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {
    LinkedList mylist;

    mylist.add(10);
    mylist.add(20);
    mylist.add(30);
    mylist.display(); // Output: 10    20    30

    mylist.InsertAfter(25, 20);
    mylist.display(); // Output: 10    20    25    30

    mylist.InsertBefore(15, 10);
    mylist.display(); // Output: 15    10    20    25    30

    cout << "Number of nodes: " << mylist.GetCount() << endl; // Output: 5

    cout << "Data at index 2: " << mylist.GetDataByIndex(2) << endl; // Output: 20
    cout << "Data at index 5: " << mylist.GetDataByIndex(5) << endl; // Output: Index 5 out of range.

    return 0;
}

