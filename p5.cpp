#include <iostream>
using namespace std;

struct ComplexNumber {
    double real;
    double imaginary;

    // Member function to add two complex numbers
    ComplexNumber add(const ComplexNumber& c) const {
        ComplexNumber result;
        result.real = real + c.real;
        result.imaginary = imaginary + c.imaginary;
        return result;
    }

    // Member function to subtract two complex numbers
    ComplexNumber subtract(const ComplexNumber& c) const {
        ComplexNumber result;
        result.real = real - c.real;
        result.imaginary = imaginary - c.imaginary;
        return result;
    }

    // Member function to multiply two complex numbers
    ComplexNumber multiply(const ComplexNumber& c) const {
        ComplexNumber result;
        result.real = real * c.real - imaginary * c.imaginary;
        result.imaginary = real * c.imaginary + imaginary * c.real;
        return result;
    }

    // Function to display a complex number in a+bi format
    void display() const {
        cout << real << (imaginary >= 0 ? "+" : "") << imaginary << "i" << endl;
    }
};

int main() {
    ComplexNumber c1, c2, result;

    // Input first complex number
    cout << "Enter first complex number (real imaginary): ";
    cin >> c1.real >> c1.imaginary;

    // Input second complex number
    cout << "Enter second complex number (real imaginary): ";
    cin >> c2.real >> c2.imaginary;

    // Add complex numbers
    result = c1.add(c2);
    cout << "Addition of two complex numbers: ";
    result.display();

    // Subtract complex numbers
    result = c1.subtract(c2);
    cout << "Subtraction of two complex numbers: ";
    result.display();

    // Multiply complex numbers
    result = c1.multiply(c2);
    cout << "Multiplication of two complex numbers: ";
    result.display();

    return 0;
}