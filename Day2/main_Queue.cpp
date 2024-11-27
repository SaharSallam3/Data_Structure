#include <iostream>
#include "Queue.h"
using namespace std;

int main() {
    Queue q(5);

    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);
    q.enQueue(40);
    q.enQueue(50);


    q.enQueue(60);

    q.display();

    int frontData, rearData;


    if (q.GetFront(frontData)) {
        cout << "Front element: " << frontData << endl;
    }

    if (q.GetRear(rearData)) {
        cout << "Rear element: " << rearData << endl;
    }


    int data;
    if (q.deQueue(data)) {
        cout << "Dequeued element: " << data << endl;
    }

    q.display();

    if (q.deQueue(data)) {
        cout << "Dequeued element: " << data << endl;
    }

    q.display();

    return 0;
}
