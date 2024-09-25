#include <iostream>
using namespace std;

void createArray(int* arr, int &size);
void insert(int* arr, int &size, int element, int pos);
void delete_ele(int* arr, int &size, int pos);
int search(int* arr, int size, int element);
int maxi(int* arr, int size);
int mini(int* arr, int size);

int main() {
    int arr[100], size = 0, choice, element, pos;

    do {
        cout << "\nMenu:\n";
        cout << "1. Create Array\n";
        cout << "2. Insert Element\n";
        cout << "3. Delete Element\n";
        cout << "4. Search Element\n";
        cout << "5. Find Max Element\n";
        cout << "6. Find Min Element\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createArray(arr, size);
                break;
            case 2:
                cout << "Enter element to insert: ";
                cin >> element;
                cout << "Enter position (0 to " << size << "): ";
                cin >> pos;
                insert(arr, size, element, pos);
                break;
            case 3:
                cout << "Enter position to delete (0 to " << size - 1 << "): ";
                cin >> pos;
                delete_ele(arr, size, pos);
                break;
            case 4:
                cout << "Enter element to search: ";
                cin >> element;
                pos = search(arr, size, element);
                if (pos != -1)
                    cout << "Element found at index: " << pos << endl;
                else
                    cout << "Element not found.\n";
                break;
            case 5:
                if (size > 0)
                    cout << "Max element: " << maxi(arr, size) << endl;
                else
                    cout << "Array is empty.\n";
                break;
            case 6:
                if (size > 0)
                    cout << "Min element: " << mini(arr, size) << endl;
                else
                    cout << "Array is empty.\n";
                break;
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}

void createArray(int* arr, int &size) {
    cout << "Enter number of elements: ";
    cin >> size;
    cout << "Enter elements:\n";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void insert(int* arr, int &size, int element, int pos) {
    if (pos < 0 || pos > size) {
        cout << "Invalid position!\n";
        return;
    }
    for (int i = size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = element;
    size++;
    cout << "Element inserted successfully.\n";
}

void delete_ele(int* arr, int &size, int pos) {
    if (pos < 0 || pos >= size) {
        cout << "Invalid position!\n";
        return;
    }
    for (int i = pos; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
    cout << "Element deleted successfully.\n";
}

int search(int* arr, int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i;
        }
    }
    return -1;
}

int maxi(int* arr, int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int mini(int* arr, int size) {
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

