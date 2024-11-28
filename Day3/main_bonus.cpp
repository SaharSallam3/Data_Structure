#include <iostream>

using namespace std;

///--------------------------------3. Bubble Sort for a Doubly Linked List (swap Nodes) -----------------------------///

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

    ///-------------------------------------------- BubbleSort by swapping nodes ----------------------------------------///


    void BubbleSort_SwapNodes() {
        if (head == NULL || head->Next == NULL) {
            return; /// No need to sort if the list is empty or has only one node.
        }

        bool swapped;

        do {
            swapped = false;
            Node *current = head;

            while (current->Next != NULL) {
                if (current->Data > current->Next->Data) {
                    /// Swap nodes
                    Node *nextNode = current->Next;

                    /// Adjust links for the previous node
                    if (current->Prev != NULL) {
                        current->Prev->Next = nextNode;
                    } else {
                        head = nextNode; /// Update head if swapping the first node
                    }

                    if (nextNode->Next != NULL) {
                        nextNode->Next->Prev = current;
                    } else {
                        tail = current; /// Update tail if swapping the last node
                    }

                    /// Update pointers for current and nextNode
                    current->Next = nextNode->Next;
                    nextNode->Prev = current->Prev;
                    current->Prev = nextNode;
                    nextNode->Next = current;

                    swapped = true;
                } else {
                    current = current->Next; /// Move to the next node
                }
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

    cout << "Bubble Sort (Swap Nodes):\n";
    list.BubbleSort_SwapNodes();
    list.display();

    return 0;
}
