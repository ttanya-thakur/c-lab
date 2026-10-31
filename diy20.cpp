#include <iostream>
using namespace std;

class Shape
{
protected:
    string color;

public:
    Shape()
    {
        color = "Red";
        cout << "Shape constructor called" << endl;
    }
};

class Polygon : public Shape
{
protected:
    int sides;

public:
    Polygon()
    {
        sides = 4;
        cout << "Polygon constructor called" << endl;
    }
};

class Rectangle : public Polygon
{
private:
    int length, breadth;

public:
    Rectangle()
    {
        length = 10;
        breadth = 5;
        cout << "Rectangle constructor called" << endl;
    }

    void display()
    {
        cout << "\nShape Details:" << endl;
        cout << "Color: " << color << endl;
        cout << "Number of sides: " << sides << endl;
        cout << "Length: " << length << endl;
        cout << "Breadth: " << breadth << endl;
        cout << "Area: " << length * breadth << endl;
    }
};

int main()
{
    cout << "Creating Rectangle object..." << endl;
    Rectangle r;
    r.display();

    return 0;
}
