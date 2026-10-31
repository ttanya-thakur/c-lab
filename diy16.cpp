#include <iostream>
using namespace std;

class Money
{
    int rupees, paise;

public:
    Money(int r = 0, int p = 0)
    {
        rupees = r + p / 100;
        paise = p % 100;
    }

    Money operator+(Money m)
    {
        Money temp;
        temp.rupees = rupees + m.rupees;
        temp.paise = paise + m.paise;
        if (temp.paise >= 100)
        {
            temp.rupees++;
            temp.paise -= 100;
        }
        return temp;
    }

    Money operator-(Money m)
    {
        Money temp;
        temp.rupees = rupees - m.rupees;
        temp.paise = paise - m.paise;
        if (temp.paise < 0)
        {
            temp.rupees--;
            temp.paise += 100;
        }
        return temp;
    }

    void display()
    {
        cout << rupees << " rupees and " << paise << " paise" << endl;
    }
};

int main()
{
    Money m1(50, 75), m2(20, 50), result;

    cout << "First amount: ";
    m1.display();

    cout << "Second amount: ";
    m2.display();

    result = m1 + m2;
    cout << "Addition: ";
    result.display();

    result = m1 - m2;
    cout << "Subtraction: ";
    result.display();

    return 0;
}
