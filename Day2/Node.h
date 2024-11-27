#ifndef NODE_H
#define NODE_H

class Node {
public:
    int Data;
    Node* Next;

    Node(int data) {
        Data = data;
        Next = NULL;
    }
};

#endif // NODE_H
