#include <iostream>
using namespace std;

const int size = 10;

void display(int matrix[size][size], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void add(int A[size][size], int B[size][size], int result[size][size], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

void multiply(int A[size][size], int B[size][size], int result[size][size], int rowsA, int colsA, int rowsB, int colsB) {
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void transpose(int matrix[size][size], int transposed[size][size], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transposed[j][i] = matrix[i][j];
        }
    }
}

int main() {
    int choice;
    int A[size][size], B[size][size], result[size][size], transposed[size][size];
    int rows, cols;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add two matrices\n";
        cout << "2. Multiply two matrices\n";
        cout << "3. Transpose a matrix\n";
        cout << "4. Display a matrix\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter number of rows and columns for matrices: ";
                cin >> rows >> cols;

                cout << "Enter elements of matrix A:\n";
                for (int i = 0; i < rows; ++i) {
                    for (int j = 0; j < cols; ++j) {
                        cin >> A[i][j];
                    }
                }

                cout << "Enter elements of matrix B:\n";
                for (int i = 0; i < rows; ++i) {
                    for (int j = 0; j < cols; ++j) {
                        cin >> B[i][j];
                    }
                }

                add(A, B, result, rows, cols);
                cout << "Result of addition:\n";
                display(result, rows, cols);
                break;
            }
            case 2: {
                int rowsB, colsB;
                cout << "Enter dimensions of matrix A (rows cols): ";
                cin >> rows >> cols;

                cout << "Enter dimensions of matrix B (rows cols): ";
                cin >> rowsB >> colsB;

                if (cols != rowsB) {
                    cout << "Matrix multiplication not possible!\n";
                    break;
                }

                cout << "Enter elements of matrix A:\n";
                for (int i = 0; i < rows; ++i) {
                    for (int j = 0; j < cols; ++j) {
                        cin >> A[i][j];
                    }
                }

                cout << "Enter elements of matrix B:\n";
                for (int i = 0; i < rowsB; ++i) {
                    for (int j = 0; j < colsB; ++j) {
                        cin >> B[i][j];
                    }
                }

                multiply(A, B, result, rows, cols, rowsB, colsB);
                cout << "Result of multiplication:\n";
                display(result, rows, colsB);
                break;
            }
            case 3: {
                cout << "Enter dimensions of matrix (rows cols): ";
                cin >> rows >> cols;

                cout << "Enter elements of the matrix:\n";
                for (int i = 0; i < rows; ++i) {
                    for (int j = 0; j < cols; ++j) {
                        cin >> A[i][j];
                    }
                }

                transpose(A, transposed, rows, cols);
                cout << "Transposed matrix:\n";
                display(transposed, cols, rows);
                break;
            }
            case 4: {
                cout << "Enter dimensions of matrix to display (rows cols): ";
                cin >> rows >> cols;

                cout << "Enter elements of the matrix:\n";
                for (int i = 0; i < rows; ++i) {
                    for (int j = 0; j < cols; ++j) {
                        cin >> A[i][j];
                    }
                }

                cout << "Matrix:\n";
                display(A, rows, cols);
                break;
            }
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

