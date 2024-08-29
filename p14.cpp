#include <iostream>

using namespace std;

class Matrix {
private:
    int rows;
    int cols;
    int **data;

public:
    // Constructor to initialize matrix with given dimensions
    Matrix(int r, int c) : rows(r), cols(c) {
        data = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[cols];
        }
    }

    // Copy constructor
    Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
        data = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[cols];
            for (int j = 0; j < cols; ++j) {
                data[i][j] = other.data[i][j];
            }
        }
    }

    // Destructor to free allocated memory
    ~Matrix() {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

    // Function to input matrix data
    void input() {
        cout << "Enter elements of matrix (" << rows << "x" << cols << "):\n";
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cin >> data[i][j];
            }
        }
    }

    // Function to display matrix data
    void display() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Function to add two matrices
    Matrix add(const Matrix& other) const {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    // Function to subtract two matrices
    Matrix subtract(const Matrix& other) const {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    // Function to multiply two matrices
    Matrix multiply(const Matrix& other) const {
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                result.data[i][j] = 0;
                for (int k = 0; k < cols; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    // Get number of columns
    int getCols() const {
        return cols;
    }

    // Get number of rows
    int getRows() const {
        return rows;
    }
};

int main() {
    int rows1, cols1, rows2, cols2, choice;

    cout << "Enter number of rows and columns for first matrix: ";
    cin >> rows1 >> cols1;

    cout << "Enter number of rows and columns for second matrix: ";
    cin >> rows2 >> cols2;

    Matrix matrix1(rows1, cols1);
    Matrix matrix2(rows2, cols2);

    cout << "Enter elements of first matrix:\n";
    matrix1.input();
    cout << "Enter elements of second matrix:\n";
    matrix2.input();

    do {
        cout << "\nMenu:\n";
        cout << "1. Add matrices\n";
        cout << "2. Subtract matrices\n";
        cout << "3. Multiply matrices\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                if (matrix1.getRows() != matrix2.getRows() || matrix1.getCols() != matrix2.getCols()) {
                    cout << "Addition requires both matrices to have the same dimensions.\n";
                    break;
                }
                Matrix result = matrix1.add(matrix2);
                cout << "Result of addition:\n";
                result.display();
                break;
            }
            case 2: {
                if (matrix1.getRows() != matrix2.getRows() || matrix1.getCols() != matrix2.getCols()) {
                    cout << "Subtraction requires both matrices to have the same dimensions.\n";
                    break;
                }
                Matrix result = matrix1.subtract(matrix2);
                cout << "Result of subtraction:\n";
                result.display();
                break;
            }
            case 3: {
                if (matrix1.getCols() != matrix2.getRows()) {
                    cout << "Multiplication requires the number of columns of the first matrix to equal the number of rows of the second matrix.\n";
                    break;
                }
                Matrix result = matrix1.multiply(matrix2);
                cout << "Result of multiplication:\n";
                result.display();
                break;
            }
            case 4:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 4);

    return 0;
}
