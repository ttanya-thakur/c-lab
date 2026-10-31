#include <iostream>
#include <algorithm>

using namespace std;

class Matrix {
private:
    int rows, cols;
    int **data;

public:
    Matrix(int m, int n) {
        rows = m;
        cols = n;
        data = new int*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new int[cols]();
        }
    }

    // Deep Copy Constructor
    Matrix(const Matrix &obj) {
        rows = obj.rows;
        cols = obj.cols;
        data = new int*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new int[cols];
            for (int j = 0; j < cols; j++) {
                data[i][j] = obj.data[i][j];
            }
        }
    }
    Matrix& operator=(Matrix temp) {
        swap(this->rows, temp.rows);
        swap(this->cols, temp.cols);
        swap(this->data, temp.data);
        return *this;
    }

    void input() {
        cout << "Enter matrix elements:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> data[i][j];
            }
        }
    }

    void display() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Destructor
    ~Matrix() {
        if (data != nullptr) {
            for (int i = 0; i < rows; i++) {
                delete[] data[i];
            }
            delete[] data;
        }
    }
};

int main() {
    int m, n;
    cout << "Enter number of rows and columns: ";
    cin >> m >> n;

    Matrix A(m, n);
    A.input();

    cout << "\nOriginal Matrix:\n";
    A.display();
    Matrix B = A; 
    cout << "\nCopied Matrix (via Constructor):\n";
    B.display();
    Matrix C(m, n);
    C = A; 
    cout << "\nAssigned Matrix (via Assignment Operator):\n";
    C.display();
    return 0;
}
