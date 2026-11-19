#include <iostream>
#include <memory>
using namespace std;

int main() {
    constexpr int SIZE = 5;
    unique_ptr<int[]> arr = make_unique<int[]>(4);

    cout << "Enter " << 4 << " numbers:\n";
    for (int i = 0; i < 4; i++) {
        cin >> arr[i];
    }

    cout << "\nArray elements are:\n";
    for (int i = 0; i < 4; i++) {
        cout << arr[i] << " ";
    }
    cout << "\nMemory is managed automatically using unique_ptr.\n";
    return 0;
}
