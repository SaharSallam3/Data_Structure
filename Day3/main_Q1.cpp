#include <iostream>

using namespace std;

///--------------------------------- 1. Linear Search with Multiple Occurrences -------------------------///

void linearSearchMultiple(int *items, int size, int search) {
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (items[i] == search) {
            cout << "Found at index: " << i << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Element not found in the array." << endl;
    }
}

int main()
{
    int arr[8] = {1, 2, 3, 2, 4, 2, 5, 6};
    cout << "Linear Search for 2:" << endl;
    linearSearchMultiple(arr, 8, 2); //output: index: 1,3,5

    cout << "\nLinear Search for 7:" << endl; //output: not found
    linearSearchMultiple(arr, 8, 7);


    return 0;
}
