#include <iostream>
using namespace std;

class Person
{
protected:
    string name;

public:
    void getPerson()
    {
        cout << "Enter name: ";
        cin >> name;
    }

    void displayPerson()
    {
        cout << "Name: " << name << endl;
    }
};

class Student : virtual public Person
{
protected:
    int rollNo;

public:
    void getStudent()
    {
        cout << "Enter roll number: ";
        cin >> rollNo;
    }

    void displayStudent()
    {
        cout << "Roll Number: " << rollNo << endl;
    }
};

class Employee : virtual public Person
{
protected:
    int employeeId;

public:
    void getEmployee()
    {
        cout << "Enter employee ID: ";
        cin >> employeeId;
    }

    void displayEmployee()
    {
        cout << "Employee ID: " << employeeId << endl;
    }
};

class TeachingAssistant : public Student, public Employee
{
public:
    void displayDetails()
    {
        displayPerson();
        displayStudent();
        displayEmployee();
    }
};

int main()
{
    TeachingAssistant ta;
    ta.getPerson();
    ta.getStudent();
    ta.getEmployee();

    cout << "\n--- Teaching Assistant Details ---" << endl;
    ta.displayDetails();

    return 0;
}
