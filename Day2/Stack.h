#ifndef STACK_H
#define STACK_H

#include "Node.h"
#include <iostream>
using namespace std;

class Stack {
    private:
        Node* top;  ///head of the linked list

    public:
        ///---------------------------Constructor ----------------------------------------------------///

        Stack() {
            top = NULL;
        }

        ///--------------------------- Push data onto the stack-----------------------------------------------///

        void push(int data) {
            Node* node = new Node(data);
            node->Next = top;
            top = node;
            cout << "Pushed " << data << " to the stack.\n";
        }

        ///--------------------------- Pop data from the stack-----------------------------------------------///

        bool pop(int& data) {
            if (top == NULL) {
                cout << "Stack is empty.\n";
                return false;
            }

            Node* temp = top;
            data = top->Data;
            top = top->Next;
            delete temp;

            cout << "Popped " << data << " from the stack.\n";
            return true;
        }

        ///---------------------------- Peek at the top element of the stack---------------------------------///

        bool peek(int& data) {
            if (top == NULL) {
                cout << "Stack is empty.\n";
                return false;
            }

            data = top->Data;
            return true;
        }

        ///---------------------------- Display the stack elements-----------------------------------------///

        void display() {
            if (top == NULL) {
                cout << "Stack is empty.\n";
                return;
            }

            Node* current = top;
            cout << "Stack elements: ";
            while (current != NULL) {
                cout << current->Data << " ";
                current = current->Next;
            }
            cout << endl;
        }

        ///--------------------------- Destructor to clean up the memory------------------------------///

        ~Stack() {
            while (top != NULL) {
                Node* temp = top;
                top = top->Next;
                delete temp;
            }
            cout << "Stack has been destroyed.\n";
        }
};

#endif // STACK_H
