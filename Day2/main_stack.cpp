#include <iostream>
#include "Stack.h"

using namespace std;

int main() {
    Stack stk;


    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.push(40);
    stk.push(50);


    stk.display();


    int data;
    if (stk.peek(data)) {
        cout << "Top element: " << data << endl;
    }


    stk.pop(data);
    stk.pop(data);
    stk.pop(data);


    stk.display();


    stk.pop(data);
    stk.pop(data);


    stk.pop(data);

    return 0;
}
