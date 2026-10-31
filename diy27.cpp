#include <iostream>
#include <exception>
using namespace std;

class MathError : public exception {
public:
    const char* what() const noexcept override {
        return "MathError: A generic math error occurred";
    }
};

class DivideByZero : public MathError {
public:
    const char* what() const noexcept override {
        return "DivideByZero: Cannot divide by zero";
    }
};

void riskyMath(int divisor) {
    if (divisor == 0) throw DivideByZero();
    if (divisor < 0)  throw MathError();
}

int main() {
    try {
        riskyMath(0);
    } 
    catch (const DivideByZero& e) {
        cout << "Caught by DivideByZero (Derived): " << e.what() << endl;
    } 
    catch (const MathError& e) {
        cout << "Caught by MathError (Base): " << e.what() << endl;
    }

    return 0;
}
