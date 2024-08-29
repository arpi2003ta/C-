#include <iostream>

using namespace std;

class B; // Forward declaration of class B

class A {
private:
    int data1;
public:
    A(int d1) : data1(d1) {}
    friend int addBoth(const A&, const B&); // Declare addBoth as a friend
};

class B {
private:
    int data2;
public:
    B(int d2) : data2(d2) {}
    friend int addBoth(const A&, const B&); // Declare addBoth as a friend
};

// Function to add the values of data1 and data2
int addBoth(const A& objA, const B& objB) {
    return objA.data1 + objB.data2;
}

int main() {
    A objA(10);
    B objB(20);

    cout << "Sum of data1 and data2: " << addBoth(objA, objB) << endl;

    return 0;
}
