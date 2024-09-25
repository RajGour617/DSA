#include <iostream>
using namespace std;

struct Node {
    int data;
    int priority;
    int order;
};

class PriorityQueue {
private:
    Node elements[100];
    int size;
    int orderCounter;

public:
    PriorityQueue(){
		size=0; 
		orderCounter=0;
	}
	
    void insert(int data, int priority) {
        if (size >= 100) {
            cout << "Queue is full!" << endl;
            return;
        }
        elements[size].data = data;
        elements[size].priority = priority;
        elements[size].order = orderCounter++;
        size++;

        for (int i = size - 1; i > 0; --i) {
            for (int j = 0; j < i; ++j) {
                if (elements[j].priority < elements[j + 1].priority || 
                    (elements[j].priority == elements[j + 1].priority && elements[j].order > elements[j + 1].order)) {
                    Node temp = elements[j];
                    elements[j] = elements[j + 1];
                    elements[j + 1] = temp;
                }
            }
        }
    }

    void remove() {
        if (size == 0) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Removed: " << elements[0].data << " with priority " << elements[0].priority << endl;
        for (int i = 1; i < size; ++i) {
            elements[i - 1] = elements[i];
        }
        size--;
    }

    void display() {
        if (size == 0) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Priority Queue:" << endl;
        for (int i = 0; i < size; ++i) {
            cout << "Data: " << elements[i].data << ", Priority: " << elements[i].priority 
                 << ", Order: " << elements[i].order << endl;
        }
    }
};

int main() {
    PriorityQueue pq;
    int choice;
    int data;
    int priority;

    do {
        cout << "\nPriority Queue Menu:\n";
        cout << "1. Insert\n";
        cout << "2. Remove\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data: ";
                cin >> data;
                cout << "Enter priority (higher value means higher priority): ";
                cin >> priority;
                pq.insert(data, priority);
                break;
            case 2:
                pq.remove();
                break;
            case 3:
                pq.display();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}

