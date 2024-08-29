#include <iostream>
#include <cmath>

using namespace std;

// Abstract base class Shape
class Shape {
public:
    // Pure virtual functions to calculate surface area and volume
    virtual double surfaceArea() = 0;
    virtual double volume() = 0;

    // Virtual destructor
    virtual ~Shape() {}
};

// Derived class for Cuboid
class Cuboid : public Shape {
private:
    double length, width, height;

public:
    Cuboid(double l, double w, double h) : length(l), width(w), height(h) {}

    double surfaceArea() override {
        return 2 * (length * width + width * height + height * length);
    }

    double volume() override {
        return length * width * height;
    }
};

// Derived class for Cone
class Cone : public Shape {
private:
    double radius, height;

public:
    Cone(double r, double h) : radius(r), height(h) {}

    double surfaceArea() override {
        double slantHeight = sqrt(radius * radius + height * height);
        return M_PI * radius * (radius + slantHeight);
    }

    double volume() override {
        return (1.0 / 3.0) * M_PI * radius * radius * height;
    }
};

// Derived class for Cylinder
class Cylinder : public Shape {
private:
    double radius, height;

public:
    Cylinder(double r, double h) : radius(r), height(h) {}

    double surfaceArea() override {
        return 2 * M_PI * radius * (radius + height);
    }

    double volume() override {
        return M_PI * radius * radius * height;
    }
};

int main() {
    Shape* shape;
    int choice;
    cout << "Choose the shape:\n1. Cuboid\n2. Cone\n3. Cylinder\n";
    cin >> choice;

    if (choice == 1) {
        double length, width, height;
        cout << "Enter the length, width, and height of the cuboid: ";
        cin >> length >> width >> height;
        shape = new Cuboid(length, width, height);
    } else if (choice == 2) {
        double radius, height;
        cout << "Enter the radius and height of the cone: ";
        cin >> radius >> height;
        shape = new Cone(radius, height);
    } else if (choice == 3) {
        double radius, height;
        cout << "Enter the radius and height of the cylinder: ";
        cin >> radius >> height;
        shape = new Cylinder(radius, height);
    } else {
        cout << "Invalid choice!" << endl;
        return 1;
    }

    cout << "Surface Area: " << shape->surfaceArea() << endl;
    cout << "Volume: " << shape->volume() << endl;

    delete shape;
    return 0;
}
