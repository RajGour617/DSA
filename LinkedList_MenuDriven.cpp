#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;       

public:
    LinkedList() {
    	head=NULL;
	}

    void createList(int data) {
        head = new Node();
        head->data = data;
        head->next = NULL;
    }

    void append(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void addAtBeginning(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

    void addAfter(int afterData, int newData) {
        Node* temp = head;
        while (temp != NULL && temp->data != afterData) {
            temp = temp->next;
        }
        if (temp != NULL) {
            Node* newNode = new Node();
            newNode->data = newData;
            newNode->next = temp->next;
            temp->next = newNode;
        } else {
        	cout << "Element " << afterData << " not found.\n";
        }
    }

    int count() {
        int cnt = 0;
        Node* temp = head;
        while (temp != NULL) {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }

    void display() {
        Node* temp = head;
        if (temp == NULL) {
            cout << "List is empty.\n";
            return;
        }
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }

    void deleteElement(int data) {
        if (head == NULL) return;

        if (head->data == data) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL && temp->next->data != data) {
            temp = temp->next;
        }

        if (temp->next == NULL) {
            cout << "Element " << data << " not found.\n";
            return;
        }

        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
    }

    void sort() {
        if (head == NULL) return;

        Node* current = head;
        Node* index = NULL;
        int temp;

        while (current != NULL) {
            index = current->next;
            while (index != NULL) {
                if (current->data > index->data) {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
                index = index->next;
            }
            current = current->next;
        }
    }

    void reverse() {
        Node* prev = NULL;
        Node* current = head;
        Node* Next = NULL;
        while (current != NULL) {
            Next = current->next;
            current->next = prev;
            prev = current;
            current = Next;
        }
        head = prev;
    }

    void merge(LinkedList& other) {
        if (head == NULL) {
            head = other.head;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = other.head;
    }

    ~LinkedList() {
        Node* current = head;
        Node* Next;
        while (current != NULL) {
            Next = current->next;
            delete current;
            current = Next;
        }
    }
};

int main() {
    LinkedList list;
    int choice, data, afterData;
    LinkedList otherList;

    do {
        cout << "Menu:\n"
                  << "1. Create List\n"
                  << "2. Append Element\n"
                  << "3. Add at Beginning\n"
                  << "4. Add Element After\n"
                  << "5. Count Elements\n"
                  << "6. Display Elements\n"
                  << "7. Delete Element\n"
                  << "8. Sort\n"
                  << "9. Reverse\n"
                  << "10. Merge with another list\n"
                  << "11. Exit\n"
                  << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter first element: ";
                cin >> data;
                list.createList(data);
                break;
            case 2:
                cout << "Enter element to append: ";
                cin >> data;
                list.append(data);
                break;
            case 3:
                cout << "Enter element to add at beginning: ";
                cin >> data;
                list.addAtBeginning(data);
                break;
            case 4:
                cout << "Enter element after which to add: ";
                cin >> afterData;
                cout << "Enter new element: ";
                cin >> data;
                list.addAfter(afterData, data);
                break;
            case 5:
                cout << "Number of elements: " << list.count() << "\n";
                break;
            case 6:
                cout << "List elements: ";
                list.display();
                break;
            case 7:
                cout << "Enter element to delete: ";
                cin >> data;
                list.deleteElement(data);
                break;
            case 8:
                list.sort();
                cout << "List sorted.\n";
                break;
            case 9:
                list.reverse();
                cout << "List reversed.\n";
                break;
            case 10:
                cout << "Creating another list.\n";
                cout << "Enter first element for second list: ";
                cin >> data;
                otherList.createList(data);
                cout << "Enter elements to append in second list (-1 to stop): ";
                while (true) {
                    cin >> data;
                    if (data == -1) break;
                    otherList.append(data);
                }
                list.merge(otherList);
                cout << "Lists merged.\n";
                break;
            case 11:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 11);

    return 0;
}

