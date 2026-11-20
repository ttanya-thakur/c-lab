// Task 2 (Weeks 7-13): Student Result Management System using C++ OOP
// Base class Student and derived class Result with virtual functions, STL vector,
// exception handling for invalid marks, file handling, templates and lambdas.

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
#include <exception>
#include <stdexcept>
#include <iomanip>
using namespace std;

const int SUBJECTS = 3;
const int PASS_MARK = 40;
const char *FILE_NAME = "student_records.txt";

class InvalidMarksException : public exception {
    string msg;
public:
    InvalidMarksException(const string &who, int subject, int value) {
        msg = "Invalid marks " + to_string(value) + " in subject " +
              to_string(subject + 1) + " for " + who + " (allowed 0-100)";
    }
    const char *what() const noexcept override { return msg.c_str(); }
};

class Student {
protected:
    string name;
    int rollNo;
public:
    Student(string n, int r) : name(n), rollNo(r) {}
    virtual ~Student() {}
    string getName() const { return name; }
    int getRollNo() const { return rollNo; }
    virtual int totalMarks() const { return 0; }
    virtual string getResult() const { return "N/A"; }
    virtual string toRecord() const { return to_string(rollNo) + "," + name; }
    virtual void display() const {
        cout << "  Roll " << rollNo << " | " << left << setw(8) << name << "\n";
    }
};

class Result : public Student {
    int marks[SUBJECTS];
public:
    Result(string n, int r, int m1, int m2, int m3) : Student(n, r) {
        int m[SUBJECTS] = {m1, m2, m3};
        for (int i = 0; i < SUBJECTS; i++) {
            if (m[i] < 0 || m[i] > 100)
                throw InvalidMarksException(n, i, m[i]);
            marks[i] = m[i];
        }
    }
    int totalMarks() const override { return marks[0] + marks[1] + marks[2]; }

    string getResult() const override {
        for (int i = 0; i < SUBJECTS; i++)
            if (marks[i] < PASS_MARK) return "FAIL";
        return "PASS";
    }
    string toRecord() const override {
        return Student::toRecord() + "," + to_string(marks[0]) + "," +
               to_string(marks[1]) + "," + to_string(marks[2]);
    }
    void display() const override {
        Student::display();
        cout << "      Marks: " << marks[0] << ", " << marks[1] << ", " << marks[2]
             << " | Total: " << totalMarks() << " | Result: " << getResult() << "\n";
    }
};

template <typename T>
T findHighest(const vector<T> &v) {
    return *max_element(v.begin(), v.end());
}

typedef vector<unique_ptr<Student>> StudentList;

// ---------- File Handling ----------
void saveToFile(const StudentList &list) {
    ofstream out(FILE_NAME);
    if (!out) throw runtime_error("Cannot open file for writing");
    for (const auto &s : list) out << s->toRecord() << "\n";
}

StudentList loadFromFile(const string &fname) {
    ifstream in(fname);
    if (!in) throw runtime_error("Cannot open file: " + fname);
    StudentList list;
    string line;
    while (getline(in, line)) {
        stringstream ss(line);
        string roll, name, a, b, c;
        getline(ss, roll, ','); getline(ss, name, ',');
        getline(ss, a, ',');    getline(ss, b, ',');   getline(ss, c, ',');
        try {
            list.push_back(make_unique<Result>(name, stoi(roll),
                                               stoi(a), stoi(b), stoi(c)));
        } catch (const exception &e) {
            cout << "  [Skipped record] " << e.what() << "\n";
        }
    }
    return list;
}

int main() {
    cout << "=== Student Result Management System ===\n";
    StudentList students;
    cout << "\n--- Adding records (exception handling) ---\n";
    string names[] = {"Vikram", "Priya", "Ananya", "Rohan", "Neha", "Karthik"};
    int roll[] = {201, 202, 203, 204, 205, 206};
    int m[][3] = {{91, 94, 96}, {74, 68, 82}, {86, 84, 81},
                  {32, 64, 70}, {58, 52, 66}, {88, 135, 76}};
    for (int i = 0; i < 6; i++) {
        try {
            students.push_back(make_unique<Result>(names[i], roll[i],
                                                   m[i][0], m[i][1], m[i][2]));
            cout << "  Added: " << names[i] << "\n";
        } catch (const InvalidMarksException &e) {
            cout << "  [Exception] " << e.what() << "\n";
        }
    }
    cout << "  Records stored in vector: " << students.size() << "\n";

    cout << "\n--- Student details (virtual function display()) ---\n";
    for (const auto &s : students) s->display();

    cout << "\n--- File handling: save and retrieve ---\n";
    saveToFile(students);
    { ofstream app(FILE_NAME, ios::app); app << "207,Sonia,75,140,68\n"; }
    cout << "  Saved " << students.size() << " records to " << FILE_NAME << "\n";
    students.clear();
    students = loadFromFile(FILE_NAME);
    cout << "  Retrieved " << students.size() << " records from file\n";
    try {
        loadFromFile("no_such_file.txt");
    } catch (const runtime_error &e) {
        cout << "  [Exception] " << e.what() << "\n";
    }

    cout << "\n--- Lambda / STL algorithms ---\n";
    const int CUTOFF = 220;
    vector<const Student *> above;
    for_each(students.begin(), students.end(), [&](const unique_ptr<Student> &s) {
        if (s->totalMarks() > CUTOFF) above.push_back(s.get());
    });
    cout << "  Students scoring above " << CUTOFF << " (total marks):\n";
    for (const Student *s : above)
        cout << "    " << s->getName() << " - " << s->totalMarks() << "\n";

    long passed = count_if(students.begin(), students.end(),
        [](const unique_ptr<Student> &s) { return s->getResult() == "PASS"; });
    cout << "  Passed: " << passed << ", Failed: " << students.size() - passed << "\n";

    sort(students.begin(), students.end(),
        [](const unique_ptr<Student> &a, const unique_ptr<Student> &b) {
            return a->totalMarks() > b->totalMarks();
        });
    cout << "  Rank list (sorted by total marks):\n";
    int rank = 1;
    for (const auto &s : students)
        cout << "    " << rank++ << ". " << left << setw(8) << s->getName()
             << s->totalMarks() << "  " << s->getResult() << "\n";

    cout << "\n--- Template function findHighest() ---\n";
    vector<int> totals;
    for (const auto &s : students) totals.push_back(s->totalMarks());
    cout << "  Highest total marks: " << findHighest(totals)
         << " (" << students[0]->getName() << ")\n";

    cout << "\nProgram ending.\n";
    return 0;
}
