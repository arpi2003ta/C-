
#include <iostream>
using namespace std;

class Counter {
private:
    int value;

public:
    // Constructor
    Counter(int v = 0);

    // Member function overloading for pre-increment
    Counter& operator++();

    // Member function overloading for post-increment
    Counter operator++(int);

    // Member function overloading for pre-decrement
    Counter& operator--();

    // Member function overloading for post-decrement
    Counter operator--(int);

    // Friend function overloading for >>
    friend istream& operator>>(istream& in, Counter& c);

    // Friend function overloading for <<
    friend ostream& operator<<(ostream& out, const Counter& c);
};

// Constructor
Counter::Counter(int v) : value(v) {}

// Member function overloading for pre-increment
Counter& Counter::operator++() {
    ++value;
    return *this;
}

// Member function overloading for post-increment
Counter Counter::operator++(int) {
    Counter temp = *this;
    value++;
    return temp;
}

// Member function overloading for pre-decrement
Counter& Counter::operator--() {
    --value;
    return *this;
}

// Member function overloading for post-decrement
Counter Counter::operator--(int) {
    Counter temp = *this;
    value--;
    return temp;
}

// Friend function overloading for >>
istream& operator>>(istream& in, Counter& c) {
    in >> c.value;
    return in;
}

// Friend function overloading for <<
ostream& operator<<(ostream& out, const Counter& c) {
    out << c.value;
    return out;
}

int main() {
    Counter c1, c2;

    // Taking user input
    cout << "Enter an initial value for c1: ";
    cin >> c1;

    cout << "Initial value of c1: " << c1 << endl;

    // Pre-increment
    ++c1;
    cout << "After pre-increment: " << c1 << endl;

    // Post-increment
    c1++;
    cout << "After post-increment: " << c1 << endl;

    // Pre-decrement
    --c1;
    cout << "After pre-decrement: " << c1 << endl;

    // Post-decrement
    c1--;
    cout << "After post-decrement: " << c1 << endl;

    // Using >> operator
    cout << "Enter a new value for c2: ";
    cin >> c2;

    // Using << operator
    cout << "New value of c2: " << c2 << endl;

    return 0;
}
