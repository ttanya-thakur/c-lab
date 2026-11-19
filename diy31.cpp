#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
T findMax(const T arr[], int n) {
    if (n <= 0) {
        throw invalid_argument("Array size must be greater than 0");
    }

    T maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

int main() {
    int a[] = {10, 25, 15, 40, 30};
    double b[] = {10.5, 25.7, 15.2, 40.8, 30.6};
    int n1 = sizeof(a) / sizeof(a[0]);
    int n2 = sizeof(b) / sizeof(b[0]);

    cout << "Maximum integer: " << findMax(a, n1) << endl;
    cout << "Maximum double: " << findMax(b, n2) << endl;

    return 0;
}
