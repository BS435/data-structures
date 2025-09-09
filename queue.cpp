#include <iostream>
using namespace std;
#define MAX 10

int front = 0, rear = 0;
bool flag;
int queue[MAX];

bool is_empty() {
    if (front == 0) {
        flag = true;
    } else {
        flag = false;
    }
    return flag;
}

bool is_full() {
    if (rear == MAX) {
        flag = true;
    } else {
        flag = false;
    }
    return flag;
}

void enqueue(int data) {
    if (rear < MAX) {
        rear++;
        queue[rear] = data;
        if (rear == 1) {
            front = 1;
        }
    } else {
        cout << "Overflow - Queue is full" << endl;
    }
}

void dequeue(int &data) {
    if (front != 0) {
        data = queue[front];
        if (front == rear) {
            front = 0;
            rear = 0;
        } else {
            front++;
        }
    } else {
        cout << "Underflow - Queue is empty" << endl;
        data = -1;
    }
}

int main() {
    int option;
    int data;
    do {
        cout << "\n1. Enqueue an element" << endl;
        cout << "2. Dequeue an element" << endl;
        cout << "3. Print queue elements" << endl;
        cout << "4. Exit" << endl;

        cin >> option;

        switch(option) {
            case 1:
                cout << "Enter data to enqueue:" << endl;
                cin >> data;
                enqueue(data);
                break;

            case 2:
                dequeue(data);
                if (data != -1)
                    cout << "Dequeued element: " << data << "\n" << endl;
                break;

            case 3: {
                if (front == 0) {
                    cout << "Queue is empty\n";
                } else {
                    for (int i = front; i <= rear; i++) {
                        cout << "[" << queue[i] << "]";
                    }
                    cout << "\n";
                }
                break;
            }

            case 4:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid input" << endl;
        }

    } while (option != 4);

    return 0;
}
