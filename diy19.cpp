#include <iostream>
using namespace std;

class Employee
{
protected:
    string name;
    int id;

public:
    void getEmployeeDetails()
    {
        cout << "Enter employee name: ";
        cin >> name;
        cout << "Enter employee ID: ";
        cin >> id;
    }

    void displayEmployeeDetails()
    {
        cout << "Employee Name: " << name << endl;
        cout << "Employee ID: " << id << endl;
    }
};

class Manager : public Employee
{
private:
    int teamSize;

public:
    void getManagerDetails()
    {
        getEmployeeDetails();
        cout << "Enter team size: ";
        cin >> teamSize;
    }

    void displayManagerDetails()
    {
        displayEmployeeDetails();
        cout << "Team Size: " << teamSize << endl;
    }
};

class Engineer : public Employee
{
private:
    string skill;

public:
    void getEngineerDetails()
    {
        getEmployeeDetails();
        cout << "Enter skill: ";
        cin >> skill;
    }

    void displayEngineerDetails()
    {
        displayEmployeeDetails();
        cout << "Skill: " << skill << endl;
    }
};

int main()
{
    Manager m;
    Engineer e;

    cout << "--- Enter Manager Details ---" << endl;
    m.getManagerDetails();

    cout << "\n--- Enter Engineer Details ---" << endl;
    e.getEngineerDetails();

    cout << "\n--- Manager Details ---" << endl;
    m.displayManagerDetails();

    cout << "\n--- Engineer Details ---" << endl;
    e.displayEngineerDetails();

    return 0;
}
