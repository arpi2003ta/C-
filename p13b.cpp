#include <iostream>

using namespace std;

class Data {
public:
    int value;

    Data(int v) : value(v) {}

    void display() const {
        cout << "Value: " << value << endl;
    }
};

// Swap function - pass by value
void swapByValue(Data a, Data b) {
    int temp = a.value;
    a.value = b.value;
    b.value = temp;
    
}

// Swap function - pass by reference
void swapByReference(Data& a, Data& b) {
    int temp = a.value;
    a.value = b.value;
    b.value = temp;
}

// Swap function - pass by address
void swapByAddress(Data* a, Data* b) {
    int temp = a->value;
    a->value = b->value;
    b->value = temp;
}

int main() {
    int val1, val2;

    cout << "Enter value for object A: ";
    cin >> val1;
    cout << "Enter value for object B: ";
    cin >> val2;

    Data objA(val1);
    Data objB(val2);

    cout << "\nInitial values:" << endl;
    cout << "Object A - "; objA.display();
    cout << "Object B - "; objB.display();

    // Pass by value
    swapByValue(objA, objB);
    cout << "After swapByValue (original objects remain unchanged):" << endl;
    cout << "Object A - "; objA.display();
    cout << "Object B - "; objB.display();

    // Pass by reference
    swapByReference(objA, objB);
    cout << "After swapByReference:" << endl;
    cout << "Object A - "; objA.display();
    cout << "Object B - "; objB.display();

   

    // Pass by address
    swapByAddress(&objA, &objB);
    cout << "After swapByAddress:" << endl;
    cout << "Object A - "; objA.display();
    cout << "Object B - "; objB.display();

    return 0;
}
