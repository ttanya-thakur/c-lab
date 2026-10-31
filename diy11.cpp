#include <iostream>
using namespace std;

class Stack
{
private:
    int *arr;
    int top;
    int size;

public:
    Stack(int n)
    {
        size = n;
        top = -1;
        arr = new int[size];
    }

    void push(int value)
    {
        if (top == size - 1)
        {
            cout << "Stack Overflow!" << endl;
        }
        else
        {
            top++;
            arr[top] = value;
            cout << value << " pushed into stack" << endl;
        }
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow!" << endl;
        }
        else
        {
            cout << arr[top] << " popped from stack" << endl;
            top--;
        }
    }

    void display()
    {
        if (top == -1)
        {
            cout << "Stack is empty!" << endl;
        }
        else
        {
            cout << "Stack elements: ";
            for (int i = top; i >= 0; i--)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }

    ~Stack()
    {
        delete[] arr;
        cout << "Stack memory released." << endl;
    }
};

int main()
{
    Stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    s.pop();
    s.display();
    return 0;
}
