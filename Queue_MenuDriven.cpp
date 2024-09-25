#include <iostream>
using namespace std;
#define MAX 5

class Queue {
private:
    int arr[MAX];
    int front;
    int rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int value) {
        if ((rear + 1) % MAX == front) {
            cout << "Queue is full. Cannot enqueue " << value << "." << endl;
            return;
        }
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % MAX;
        arr[rear] = value;
        cout << "Enqueued: " << value << endl;
    }

    void dequeue() {
        if (front == -1) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }
        cout << "Dequeued: " << arr[front] << endl;
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
    }

    void display() {
        if (front == -1) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    int choice, value;

    do {
        cout << "\nQueue Operations Menu" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please enter again." << endl;
        }
    } while (choice != 4);

    return 0;
}

