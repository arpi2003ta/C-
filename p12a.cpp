#include <iostream>

using namespace std;

class A {
private:
    int data1;

public:
    void setData1(int value) {
        data1 = value;
    }

    int getData1() const {
        return data1;
    }
};

class B {
private:
    int data2;

public:
    void setData2(int value) {
        data2 = value;
    }

    int getData2() const {
        return data2;
    }
};

// Function to add data1 from class A and data2 from class B
int addBoth(const A& a, const B& b) {
    return a.getData1() + b.getData2();
}

int main() {
    A a;
    B b;
    int value1, value2;

    // Taking user input for data1 and data2
    cout << "Enter value for data1 in class A: ";
    cin >> value1;
    a.setData1(value1);

    cout << "Enter value for data2 in class B: ";
    cin >> value2;
    b.setData2(value2);

    // Adding the values and displaying the result
    int result = addBoth(a, b);
    cout << "The sum of data1 and data2 is: " << result << endl;

    return 0;
}
