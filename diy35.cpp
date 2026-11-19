#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

int main() {
    int N, num;
    cout << "Enter the number of elements: ";
    cin >> N;

    if (N < 3) {
        cout << "Please enter at least 3 numbers." << endl;
        return 0;
    }
    priority_queue<int, vector<int>, greater<int>> minHeap;

    cout << "Enter " << N << " numbers:\n";
    for (int i = 0; i < N; i++) {
        cin >> num;
        minHeap.push(num);
        if (minHeap.size() > 3) {
            minHeap.pop();
        }
    }
    int top3[3];
    for (int i = 2; i >= 0; i--) {
        top3[i] = minHeap.top();
        minHeap.pop();
    }

    cout << "Three largest numbers are:\n";
    for (int val : top3) {
        cout << val << endl;
    }

    return 0;
}