#include <iostream>

using namespace std;

// Base class
class Base {
public:
    // Constructor
    Base() {
        cout << "Base class constructor called." << endl;
    }

    // Non-virtual function (Early binding)
    void display() {
        cout << "Display function from Base class (Early binding)." << endl;
    }

    // Virtual function (Late binding)
    virtual void show() {
        cout << "Show function from Base class (Late binding)." << endl;
    }

    // Destructor
    virtual ~Base() {
        cout << "Base class destructor called." << endl;
    }
};

// Derived class
class Derived : public Base {
public:
    // Constructor
    Derived() {
        cout << "Derived class constructor called." << endl;
    }

    // Overridden function (Early binding for non-virtual functions)
    void display() {
        cout << "Display function from Derived class (Early binding)." << endl;
    }

    // Overridden virtual function (Late binding)
    void show() override {
        cout << "Show function from Derived class (Late binding)." << endl;
    }

    // Destructor
    ~Derived() {
        cout << "Derived class destructor called." << endl;
    }
};

int main() {
    cout << "Creating a Base object..." << endl;
    Base baseObj;
    baseObj.display();  // Early binding
    baseObj.show();     // Early binding (Base class function called)

    cout << "\nCreating a Derived object..." << endl;
    Derived derivedObj;
    derivedObj.display();  // Early binding
    derivedObj.show();     // Early binding (Derived class function called)

    cout << "\nCreating a Derived object through a Base pointer..." << endl;
    Base* basePtr = new Derived;
    basePtr->display();  // Early binding (Base class function called)
    basePtr->show();     // Late binding (Derived class function called)

    delete basePtr;  // Proper destruction of the derived object

    return 0;
}
