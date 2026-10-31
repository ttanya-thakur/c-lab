#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student
{
public:
    string name;
    int marks;
};

int main()
{
    Student s[5];
    ofstream out("students.txt");

    if (!out)
    {
        cout << "Error opening file!";
        return 1;
    }

    cout << "Enter names and marks of 5 students:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter name: ";
        cin >> s[i].name;
        cout << "Enter marks: ";
        cin >> s[i].marks;
        out << s[i].name << " " << s[i].marks << endl;
    }
    out.close();

    ifstream in("students.txt");
    if (!in)
    {
        cout << "Error reading file!";
        return 1;
    }

    for (int i = 0; i < 5; i++)
    {
        in >> s[i].name >> s[i].marks;
    }
    in.close();

    int topper = 0;
    for (int i = 1; i < 5; i++)
    {
        if (s[i].marks > s[topper].marks)
        {
            topper = i;
        }
    }

    cout << "\nTopper Details:\n";
    cout << "Name: " << s[topper].name << endl;
    cout << "Marks: " << s[topper].marks << endl;

    return 0;
}
