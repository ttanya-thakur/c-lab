#include <iostream>
#include <stdexcept>
using namespace std;

class InsufficientFunds : public exception
{
public:
    const char* what() const noexcept override
    {
        return "Insufficient funds! Withdrawal cannot be completed.";
    }
};

class BankAccount
{
private:
    double balance;

public:
    BankAccount(double b)
    {
        balance = b;
    }

    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Amount deposited successfully." << endl;
        }
        else
        {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    void withdraw(double amount)
    {
        if (amount <= 0)
        {
            throw invalid_argument("Withdrawal amount must be positive.");
        }
        if (amount > balance)
        {
            throw InsufficientFunds();
        }
        balance -= amount;
        cout << "Withdrawal successful." << endl;
    }

    void displayBalance()
    {
        cout << "Current Balance: Rs. " << balance << endl;
    }
};

int main()
{
    BankAccount account(5000);
    double amount;

    account.displayBalance();
    cout << "Enter withdrawal amount: ";
    cin >> amount;

    try
    {
        account.withdraw(amount);
        account.displayBalance();
    }
    catch (const InsufficientFunds& e)
    {
        cout << "Exception: " << e.what() << endl;
        account.displayBalance();
    }
    catch (const invalid_argument& e)
    {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
