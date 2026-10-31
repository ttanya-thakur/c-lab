#include <iostream>
using namespace std;
class Counter
{
private:
int count;
public:
Counter()
{
count = 0;
}
void increment()
{
count++;
}
void reset()
{
count = 0;
}
int get()
{
return count;
}
};
int main()
{
Counter counters[3];
counters[0].increment();
counters[0].increment();
counters[1].increment();
counters[1].increment();
counters[1].increment();
counters[2].increment();
cout << "Counter 1 = " << counters[0].get() << endl;
cout << "Counter 2 = " << counters[1].get() << endl;
cout << "Counter 3 = " << counters[2].get() << endl;
counters[1].reset();
cout << "\nAfter resetting Counter 2:" << endl;
cout << "Counter 1 = " << counters[0].get() << endl;
cout << "Counter 2 = " << counters[1].get() << endl;
cout << "Counter 3 = " << counters[2].get() << endl;
return 0;
}