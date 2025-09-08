#include <iostream>
using namespace std;

#define MAX 10
int top = -1;
int stack[MAX];

bool stack_is_empty() {
    if (top == -1) {
        return true;
    } else {
        return false;
    }
}

bool stack_is_full() {
    if (top == MAX - 1) {
        return true;
    } else {
        return false;
    }
}

void push(int data) {
    if (stack_is_full()) {
        cout << "Overflow - Stack is full" << endl;
    } else {
        top++;
        stack[top] = data;
    }
}

int pop() {
    if (stack_is_empty()) {
        cout << "Underflow - Stack is empty" << endl;
        return -1;
    } else {
        int data = stack[top];
        top--;
        return data;
    }
}

int main() {
    
    push(10);
    push(20);
    push(30);

    cout << "Popped element: " << pop() << endl;
    cout << "Popped element: " << pop() << endl;
    cout << "Popped element: " << pop() << endl;
    cout << "Popped element: " << pop() << endl;

    return 0;
}
