#include <iostream>
using namespace std;

class Account
{
protected:
    double balance;

public:
    Account(double b)
    {
        balance = b;
    }

    virtual double calculateInterest() = 0;

    virtual void display()
    {
        cout << "Balance: " << balance << endl;
        cout << "Interest: " << calculateInterest() << endl;
    }

    virtual ~Account() {}
};

class Savings : public Account
{
public:
    Savings(double b) : Account(b) {}

    double calculateInterest() override
    {
        return balance * 0.05;
    }
};

class Current : public Account
{
public:
    Current(double b) : Account(b) {}

    double calculateInterest() override
    {
        return balance * 0.03;
    }
};

int main()
{
    Account* accounts[2];
    Savings s(10000);
    Current c(20000);

    accounts[0] = &s;
    accounts[1] = &c;

    cout << "--- Savings Account ---" << endl;
    accounts[0]->display();

    cout << "\n--- Current Account ---" << endl;
    accounts[1]->display();

    return 0;
}
