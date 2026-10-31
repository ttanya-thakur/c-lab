#include <iostream>
using namespace std;

class Tracer
{
private:
    int id;

public:
    Tracer(int n)
    {
        id = n;
        cout << "Tracer " << id << " created" << endl;
    }

    ~Tracer()
    {
        cout << "Tracer " << id << " destroyed" << endl;
    }
};

int main()
{
    cout << "Creating and deleting Tracers:\n";
    for (int i = 1; i <= 5; i++)
    {
        Tracer *t = new Tracer(i);
        delete t;
    }

    cout << "\nNow creating Tracers without delete:\n";
    for (int i = 6; i <= 10; i++)
    {
        Tracer *t = new Tracer(i);
    }

    cout << "\nProgram ended." << endl;
    return 0;
}
