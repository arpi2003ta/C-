#include <iostream>
using namespace std;

class ComplexNumber {
private:
    double real;
    double imaginary;

public:
    // Constructor to initialize complex number
    ComplexNumber(double r = 0, double i = 0) : real(r), imaginary(i) {}

    // Function to add two complex numbers
    ComplexNumber add(const ComplexNumber& other) const;

    // Function to subtract two complex numbers
    ComplexNumber subtract(const ComplexNumber& other) const;

    // Function to multiply two complex numbers
    ComplexNumber multiply(const ComplexNumber& other) const;

    // Function to display complex number
    void display() const;
};

ComplexNumber ComplexNumber::add(const ComplexNumber& other) const {
    return ComplexNumber(real + other.real, imaginary + other.imaginary);
}

ComplexNumber ComplexNumber::subtract(const ComplexNumber& other) const {
    return ComplexNumber(real - other.real, imaginary - other.imaginary);
}

ComplexNumber ComplexNumber::multiply(const ComplexNumber& other) const {
    double r = real * other.real - imaginary * other.imaginary;
    double i = real * other.imaginary + imaginary * other.real;
    return ComplexNumber(r, i);
}

void ComplexNumber::display() const {
    cout << real << (imaginary >= 0 ? "+" : "") << imaginary << "i" << endl;
}

int main() {
    ComplexNumber c1, c2, c3;

    // Input first complex number
    double real1, imag1;
    cout << "Enter first complex number (real and imaginary parts): ";
    cin >> real1 >> imag1;
    c1 = ComplexNumber(real1, imag1);

    // Input second complex number
    double real2, imag2;
    cout << "Enter second complex number (real and imaginary parts): ";
    cin >> real2 >> imag2;
    c2 = ComplexNumber(real2, imag2);

    // Add complex numbers
    c3 = c1.add(c2);
    cout << "Addition of two complex numbers: ";
    c3.display();

    // Subtract complex numbers
    c3 = c1.subtract(c2);
    cout << "Subtraction of two complex numbers: ";
    c3.display();

    // Multiply complex numbers
    c3 = c1.multiply(c2);
    cout << "Multiplication of two complex numbers: ";
    c3.display();

    return 0;
}
