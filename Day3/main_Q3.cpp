#include <iostream>

using namespace std;

///--------------------------------3. Bubble Sort for a Doubly Linked List (swap Data) -----------------------------///

///-------------------------------------------- Class Node ----------------------------------------///

class Node {
public:
    int Data;
    Node *Prev, *Next;

    Node(int data) {
        Data = data;
        Prev = Next = NULL;
    }
};

///-------------------------------------------- Class LinkedList ----------------------------------------///

class LinkedList {
private:
    Node *head;
    Node *tail;

public:
    LinkedList() {
        head = tail = NULL;
    }

    void add(int data) {
        Node *node = new Node(data);
        if (head == NULL) {
            head = tail = node;
        } else {
            tail->Next = node;
            node->Prev = tail;
            tail = node;
        }
    }

    void display() {
        Node *current = head;
        if (current == NULL) {
            cout << "Linked List is Empty\n";
            return;
        }
        while (current != NULL) {
            cout << current->Data << "\t";
            current = current->Next;
        }
        cout << endl;
    }

    ///-------------------------------------------- BubbleSort by swapping data ----------------------------------------///

    void BubbleSort_SwapData() {
        if (head == NULL || head->Next == NULL) {
            return; /// No need to sort if the list is empty or has only one node.
        }

        bool swapped;
        Node *current;

        do {
            swapped = false;
            current = head;

            while (current->Next != NULL) { /// Traverse the list
                if (current->Data > current->Next->Data) {
                    /// Swap data
                    int temp = current->Data;
                    current->Data = current->Next->Data;
                    current->Next->Data = temp;

                    swapped = true;
                }
                current = current->Next;
            }
        } while (swapped); /// Repeat until no swaps are made
    }


};

///---------------------------------------------- Testingggg ----------------------------------///

int main() {
    LinkedList list;

    list.add(4);
    list.add(2);
    list.add(5);
    list.add(1);
    list.add(3);

    cout << "Original List:\n";
    list.display();

    cout << "Bubble Sort (Swap Data):\n";
    list.BubbleSort_SwapData();
    list.display();

    return 0;
}
