#include <iostream>
using namespace std;

class Time {
private:
    int hh, mm;

public:
    Time(int h, int m) {
        hh = h;
        mm = m;
    }

    friend Time laterOf(Time, Time);

    void display() {
        cout << hh << ":" << mm << endl;
    }
};

Time laterOf(Time t1, Time t2) {
    if (t1.hh > t2.hh)
        return t1;
    else if (t1.hh < t2.hh)
        return t2;
    else {
        if (t1.mm > t2.mm)
            return t1;
        else
            return t2;
    }
}

int main() {
    Time t1(10, 30);
    Time t2(12, 15);

    cout << "First time: ";
    t1.display();

    cout << "Second time: ";
    t2.display();

    Time result = laterOf(t1, t2);
    cout << "Later time: ";
    result.display();

    return 0;
}
