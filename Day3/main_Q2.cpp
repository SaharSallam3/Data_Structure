#include <iostream>

using namespace std;

///---------------------------------- 2. Binary Search Implementation ------------------------------///

int binarySearchIndex(int *items, int size, int search) {
    int start = 0, end = size - 1, mid = 0;

    while (start <= end) {
        mid = (start + end) / 2;

        if (items[mid] == search) {

            return mid; /// Return the index if found

        } else if (items[mid] > search) {

            end = mid - 1; /// Move to the left half

        } else {
            start = mid + 1; /// Move to the right half
        }
    }
    return -1; /// Not found
}

int main()
{
    int sortedArr[6] = {1, 2, 3, 4, 5, 6};
    int target = 7;
    int result = binarySearchIndex(sortedArr, 6, target);

    if (result != -1) {
        cout << "Binary Search: Found at index " << result << endl;
    } else {
        cout << "Binary Search: Not Found" << endl;
    }
    return 0;
}
