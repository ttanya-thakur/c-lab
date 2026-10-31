#include <iostream>
#include <exception>
using namespace std;

class Overflow : public exception
{
public:
    const char* what() const noexcept override
    {
        return "Stack Overflow! Stack is full.";
    }
};

class Underflow : public exception
{
public:
    const char* what() const noexcept override
    {
        return "Stack Underflow! Stack is empty.";
    }
};

class Stack
{
private:
    int arr[3];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(int value)
    {
        if (top == 2)
            throw Overflow();
        arr[++top] = value;
        cout << value << " pushed into stack." << endl;
    }

    void pop()
    {
        if (top == -1)
            throw Underflow();
        cout << arr[top--] << " popped from stack." << endl;
    }

    void display()
    {
        if (top == -1)
        {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main()
{
    Stack s;

    try
    {
        s.push(10);
        s.push(20);
        s.push(30);
        s.push(40);  
    }
    catch (const Overflow& e)
    {
        cout << "Exception: " << e.what() << endl;
    }

    s.display();

    try
    {
        s.pop();
        s.pop();
        s.pop();
        s.pop();
    }
    catch (const Underflow& e)
    {
        cout << "Exception: " << e.what() << endl;
    }

    s.display();

    return 0;
}
