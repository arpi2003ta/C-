#include <iostream>

using namespace std;

class MyClass {
public:
    int data;

    MyClass(int d) : data(d) {}

    void display() const {
        cout << "Data: " << data << endl;
    }
};

// Function to swap using pass by value
void swapDataByValue(MyClass obj1, MyClass obj2) {
    int temp = obj1.data;
    obj1.data = obj2.data;
    obj2.data = temp;
}

// Function to swap using pass by reference
void swapDataByReference(MyClass& obj1, MyClass& obj2) {
    int temp = obj1.data;
    obj1.data = obj2.data;
    obj2.data = temp;
}

// Function to swap using pass by address
void swapDataByAddress(MyClass* obj1, MyClass* obj2) {
    int temp = obj1->data;
    obj1->data = obj2->data;
    obj2->data = temp;
}

int main() {
    MyClass obj1(10);
    MyClass obj2(20);

    cout << "Original values:" << endl;
    obj1.display();
    obj2.display();

    // Swapping using pass by value (this will not affect the original objects)
    swapDataByValue(obj1, obj2);
    cout << "\nAfter swapping using pass by value:" << endl;
    obj1.display();
    obj2.display();

    // Swapping using pass by reference (this will swap the original objects)
    swapDataByReference(obj1, obj2);
    cout << "\nAfter swapping using pass by reference:" << endl;
    obj1.display();
    obj2.display();

    // Swapping using pass by address (this will swap the original objects)
    swapDataByAddress(&obj1, &obj2);
    cout << "\nAfter swapping using pass by address:" << endl;
    obj1.display();
    obj2.display();

    return 0;
}
