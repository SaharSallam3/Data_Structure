#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"

using namespace std;

class LinkedList
{
    private:
        Node *head;
        Node *tail;

        Node *getNodeUsingData(int data) {
            Node *current = head;
            while (current != NULL) {
                if (current->Data == data) {
                    return current;
                }
                current = current->Next;
            }
            return NULL;
        }

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

        ///-------------------------------------------------------------------------------------------------///

        void InsertAfter(int data, int afterData) {
            Node *afterNode = getNodeUsingData(afterData);
            if (afterNode == NULL) {
                cout << "Node with data " << afterData << " not found.\n";
                return;
            }

            Node *node = new Node(data);
            node->Next = afterNode->Next;
            node->Prev = afterNode;

            if (afterNode->Next != NULL) {
                afterNode->Next->Prev = node;
            } else {
                tail = node; // Update tail if inserting at the end
            }

            afterNode->Next = node;
        }

        ///---------------------------------------------------------------------------------------------///

        void InsertBefore(int data, int beforeData) {
            Node *beforeNode = getNodeUsingData(beforeData);
            if (beforeNode == NULL) {
                cout << "Node with data " << beforeData << " not found.\n";
                return;
            }

            Node *node = new Node(data);
            node->Next = beforeNode;
            node->Prev = beforeNode->Prev;

            if (beforeNode->Prev != NULL) {
                beforeNode->Prev->Next = node;
            } else {
                head = node; // Update head if inserting at the beginning
            }

            beforeNode->Prev = node;
        }

        ///-----------------------------------------------------------------------------------------///

        int GetCount() {
            int count = 0;
            Node *current = head;
            while (current != NULL) {
                count++;
                current = current->Next;
            }
            return count;
        }

        ///---------------------------------------------------------------------------------------///
        int GetDataByIndex(int index) {
            if (index < 0) {
                cout << "Invalid index.\n";
                return -1;
            }

            int currentIndex = 0;
            Node *current = head;
            while (current != NULL) {
                if (currentIndex == index) {
                    return current->Data;
                }
                currentIndex++;
                current = current->Next;
            }

            cout << "Index " << index << " out of range.\n";
            return -1;
        }

        ///-----------------------------------------------------------------------------------------------///

};

#endif // LINKEDLIST_H
