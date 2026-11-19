#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

int total1 = 0;
int total2 = 0;
mutex mtx;

void addWithoutLock() {
    for (int i = 0; i < 100000; i++) {
        total1++;
    }
}

void addWithLock() {
    for (int i = 0; i < 100000; i++) {
        lock_guard<mutex> lock(mtx);
        total2++;
    }
}

int main() {
    thread t1(addWithoutLock);
    thread t2(addWithoutLock);
    t1.join();
    t2.join();
    cout << "Total without lock_guard: " << total1 << endl;

    thread t3(addWithLock);
    thread t4(addWithLock);
    t3.join();
    t4.join();
    cout << "Total with lock_guard: " << total2 << endl;

    return 0;
}