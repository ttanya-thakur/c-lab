#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

class Fraction
{
    int num, den;

public:
    Fraction(int n = 0, int d = 1)
    {
        num = n;
        den = d;
        int g = gcd(num, den);
        num = num / g;
        den = den / g;
    }

    Fraction operator+(Fraction f)
    {
        Fraction temp;
        temp.num = num * f.den + f.num * den;
        temp.den = den * f.den;
        int g = gcd(temp.num, temp.den);
        temp.num /= g;
        temp.den /= g;
        return temp;
    }

    Fraction operator-(Fraction f)
    {
        Fraction temp;
        temp.num = num * f.den - f.num * den;
        temp.den = den * f.den;
        int g = gcd(temp.num, temp.den);
        temp.num /= g;
        temp.den /= g;
        return temp;
    }

    void display()
    {
        cout << num << "/" << den << endl;
    }
};

int main()
{
    Fraction f1(1, 2), f2(1, 3), result;

    cout << "First fraction: ";
    f1.display();

    cout << "Second fraction: ";
    f2.display();

    result = f1 + f2;
    cout << "Addition: ";
    result.display();

    result = f1 - f2;
    cout << "Subtraction: ";
    result.display();

    return 0;
}
