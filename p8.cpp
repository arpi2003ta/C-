#include <iostream>
#include <cmath>

using namespace std;

class Shape {
public:
    // Method to calculate the area of a square
    int Area(int side) {
        return side * side;
    }

    // Method to calculate the area of a rectangle
    int Area(int length, int width) {
        return length * width;
    }

    // Method to calculate the area of a circle
    float Area(float radius) {
        return M_PI * radius * radius;
    }
};

int main() {
    Shape shape;
    int choice;

    do {
        cout << "Menu:\n";
        cout << "1. Calculate area of square\n";
        cout << "2. Calculate area of rectangle\n";
        cout << "3. Calculate area of circle\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int side;
                cout << "Enter the side length of the square: ";
                cin >> side;
                cout << "Area of square: " << shape.Area(side) << "\n";
                break;
            }
            case 2: {
                int length, width;
                cout << "Enter the length and width of the rectangle: ";
                cin >> length >> width;
                cout << "Area of rectangle: " << shape.Area(length, width) << "\n";
                break;
            }
            case 3: {
                float radius;
                cout << "Enter the radius of the circle: ";
                cin >> radius;
                cout << "Area of circle: " << shape.Area(radius) << "\n";
                break;
            }
            case 4:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 4);

    return 0;
}