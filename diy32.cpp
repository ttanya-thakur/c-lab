#include <iostream>
#include <string>
using namespace std;

template <typename T, int CAPACITY = 100>
class Queue {
    T arr[CAPACITY];
    int frontIndex, rear, size;

public:
    Queue() : frontIndex(0), rear(-1), size(0) {}

    bool isEmpty() const { return size == 0; }
    bool isFull() const { return size == CAPACITY; }

    void enqueue(const T& value) {
        if (isFull()) {
            cout << "Queue is full!" << endl;
            return;
        }
        rear = (rear + 1) % CAPACITY;
        arr[rear] = value;
        size++;
        cout << value << " inserted into queue." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << arr[frontIndex] << " removed from queue." << endl;
        frontIndex = (frontIndex + 1) % CAPACITY;
        size--;
    }

    void front() const {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Front element: " << arr[frontIndex] << endl;
    }
};

int main() {
    Queue<string> q;
    q.enqueue("Apple");
    q.enqueue("Banana");
    q.enqueue("Mango");
    q.front();
    q.dequeue();
    q.front();

    return 0;
}