#ifndef QUEUE_H
#define QUEUE_H

using namespace std;

class Queue {
    private:
        int *arr;
        int front, rear, size;

    public:
        ///---------------------------------------- Constructor ----------------------------------///

        Queue(int size) {
            this->size = size;
            arr = new int[size];
            front = -1;
            rear = -1;
        }

        /// ----------------------------------------- enQueue ------------------------------------///

        void enQueue(int data) {
            if (rear == size - 1) {
                cout << "Queue is full, cannot enqueue " << data << endl;
            } else {
                if (front == -1) {
                    front = 0;
                }
                rear++;
                arr[rear] = data;
                cout << "Enqueued " << data << endl;
            }
        }

        ///------------------------------------------ deQueue --------------------------------------///

        bool deQueue(int &data) {
            if (front == -1 || front > rear) {
                cout << "Queue is empty, cannot dequeue." << endl;
                return false;
            } else {
                data = arr[front];
                front++;
                return true;
            }
        }

        ///------------------------------------------- GetFront ------------------------------------///

        bool GetFront(int &data) {
            if (front == -1 || front > rear) {
                cout << "Queue is empty, no front element." << endl;
                return false;
            } else {
                data = arr[front];
                return true;
            }
        }

        ///-------------------------------------------- GetRear -------------------------------------///

        bool GetRear(int &data) {
            if (front == -1 || front > rear) {
                cout << "Queue is empty, no rear element." << endl;
                return false;
            } else {
                data = arr[rear];
                return true;
            }
        }

        ///------------------------------------------- Display ----------------------------------------///

        void display() {
            if (front == -1 || front > rear) {
                cout << "Queue is empty." << endl;
            } else {
                cout << "Queue elements: ";
                for (int i = front; i <= rear; i++) {
                    cout << arr[i] << " ";
                }
                cout << endl;
            }
        }

        ///----------------------------------------- Destructor --------------------------------------///
        ~Queue() {
            delete[] arr;
        }
};

#endif // QUEUE_H
