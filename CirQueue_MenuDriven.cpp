#include <iostream>
using namespace std;

class CircularQueue {
private:
    int size;
    int* queue;
    int front, rear;

public:
    CircularQueue(int s) {
        size = s;
        queue = new int[size];
        front = rear = -1;
    }

    ~CircularQueue() {
        delete queue;
    }

    void enqueue(int value) {
        if ((rear + 1) % size == front) {
            cout << "Queue is full!" << endl;
        } else {
            if (front == -1) {
                front = rear = 0;
            } else {
                rear = (rear + 1) % size;
            }
            queue[rear] = value;
            cout << "Enqueued: " << value << endl;
        }
    }

    void dequeue() {
        if (front == -1) {
            cout << "Queue is empty!" << endl;
        } else {
            int temp = queue[front];
            if (front == rear) { 
                front = rear = -1;
            } else {
                front = (front + 1) % size;
            }
            cout << "Dequeued: " << temp << endl;
        }
    }

    void display() {
        if (front == -1) {
            cout << "Queue is empty!" << endl;
        } else {
            cout << "Queue elements: ";
            int i = front;
            while (true) {
                cout << queue[i] << " ";
                if (i == rear) break;
                i = (i + 1) % size;
            }
            cout << endl;
        }
    }
};

int main() {
    int size;
    cout << "Enter the size of the circular queue: ";
    cin >> size;

    CircularQueue cq(size);
    int choice, value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                cq.enqueue(value);
                break;
            case 2:
                cq.dequeue();
                break;
            case 3:
                cq.display();
                break;
            case 4:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}

