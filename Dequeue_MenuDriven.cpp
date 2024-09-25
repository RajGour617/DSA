#include <iostream>
using namespace std;

class Deque {
    int* arr;
    int front, rear, capacity;

public:
    Deque(int size){
		 this->capacity=size;
		front=-1, rear=0;
        arr = new int[size];
    }

    ~Deque() {
		delete arr; 
	}

    bool isFull() {
		return (front==0&&rear == capacity - 1) || (front == rear + 1);
	}
    bool isEmpty() {
		return front == -1; 
	}

    void insertFront(int val) {
        if (isFull()) return;
        if (isEmpty()) front = rear = 0;
        else{
        	if(front==0)
        		front=capacity-1;
        	else
				front=front-1;
		}
        arr[front] = val;
    }

    void insertRear(int val) {
        if (isFull()) return;
        if (isEmpty()) front = rear = 0;
        else rear = (front!=0 && rear == capacity - 1) ? 0 : rear + 1;
        arr[rear] = val;
    }

    void deleteFront() {
        if (isEmpty()) return;
        if (front == rear) front = rear = -1;
        else front = (front == capacity - 1) ? 0 : front + 1;
    }

    void deleteRear() {
        if (isEmpty()) return;
        if (front == rear) front = rear = -1;
        else rear = (rear == 0) ? capacity - 1 : rear - 1;
    }

    void display() {
        if (isEmpty()) { cout << "Deque is empty!" << endl; return; }
        cout << "Deque elements: ";
        for (int i = front; i != rear; i = (i + 1) % capacity)
            cout << arr[i] << " ";
        cout << arr[rear] << endl;
    }
};

int main() {
    Deque dq(5);
    int choice, value;

    do {
        cout << "\n1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Exit\nChoice: ";
        cin >> choice;

        switch (choice) {
            case 1:
				cout << "Value: "; cin >> value;
				dq.insertFront(value);
				break;
            case 2: 
				cout << "Value: ";
				cin >> value; 
				dq.insertRear(value); 
				break;
            case 3: 
				dq.deleteFront(); 
				break;
            case 4: 
				dq.deleteRear(); 
				break;
            case 5: 
				dq.display(); 
				break;
            case 6: 
				cout << "Exiting..." << endl; 
				break;
            default: 
				cout << "Invalid choice!" << endl;
        }
    } while (choice != 6);

    return 0;
}

