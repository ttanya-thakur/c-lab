#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Logger
{
public:
    virtual void write(string message) = 0;
    virtual ~Logger() {}
};

class ConsoleLogger : public Logger
{
public:
    void write(string message) override
    {
        cout << "Console Log: " << message << endl;
    }
};

class FileLogger : public Logger
{
public:
    void write(string message) override
    {
        ofstream file("log.txt", ios::app);
        if (file.is_open())
        {
            file << "File Log: " << message << endl;
            file.close();
            cout << "Message written to file successfully." << endl;
        }
        else
        {
            cout << "Error opening file!" << endl;
        }
    }
};

int main()
{
    Logger* logger;
    ConsoleLogger console;
    FileLogger file;
    int choice;
    string message;

    cout << "Choose Logger Type:" << endl;
    cout << "1. Console Logger" << endl;
    cout << "2. File Logger" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore();

    cout << "Enter message: ";
    getline(cin, message);

    if (choice == 1)
    {
        logger = &console;
    }
    else if (choice == 2)
    {
        logger = &file;
    }
    else
    {
        cout << "Invalid choice!" << endl;
        return 0;
    }

    logger->write(message);

    return 0;
}
