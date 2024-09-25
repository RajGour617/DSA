#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() {
		top=NULL;
	}

    void push(int value) {
        Node* temp = new Node();
        temp->data = value;
        temp->next = top;
        top = temp;
        cout << value << " pushed to stack" << endl;
    }

    void pop() {
        if (top==NULL) {
            cout << "Stack is empty" << endl;
            return;
        }
        Node* temp = top;
        cout << top->data << " popped from stack" << endl;
        top = top->next;
        delete temp;
    }

    void peek() {
        if (top==NULL) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Top element is " << top->data << endl;
    }

    void display() {
        if (top==NULL) {
            cout << "Stack is empty" << endl;
            return;
        }
        Node* temp = top;
        cout << "Stack elements are: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~Stack() {
        while (top!=NULL) {
            pop();
        }
    }
};

int main() {
    Stack s;
    int choice, value;

    do {
        cout << "\nStack Menu\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.peek();
                break;
            case 4:
                s.display();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 5);

    return 0;
}

