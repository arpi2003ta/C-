#include <iostream>
#include <cstring>

using namespace std;

class Student {
private:
    string name;
    int roll;
    int marks[3];

public:
    // Method to input student details
    void input();

    // Method to display student details
    void display() const;

    // Method to calculate the total marks
    int totalMarks() const;

    // Method to check if this student has more marks than another
    bool isTopper(const Student& other) const;
};

// Define the member functions outside the class

void Student::input() {
    cout << "Enter name: ";
    cin.ignore(); // To ignore the newline character left by previous input
    getline(cin, name);
    cout << "Enter roll number: ";
    cin >> roll;
    cout << "Enter marks for three subjects: ";
    for (int i = 0; i < 3; ++i) {
        cin >> marks[i];
    }
}

void Student::display() const {
    cout << "Name: " << name << "\n";
    cout << "Roll Number: " << roll << "\n";
    cout << "Marks: ";
    for (int i = 0; i < 3; ++i) {
        cout << marks[i] << " ";
    }
    cout << "\n";
}

int Student::totalMarks() const {
    return marks[0] + marks[1] + marks[2];
}

bool Student::isTopper(const Student& other) const {
    return totalMarks() > other.totalMarks();
}

// Function to find the topper among an array of students
Student max(const Student students[], int size) {
    Student topper = students[0];
    for (int i = 1; i < size; ++i) {
        if (students[i].isTopper(topper)) {
            topper = students[i];
        }
    }
    return topper;
}

int main() {
    const int numStudents = 5;
    Student students[numStudents];

    // Input data for each student
    for (int i = 0; i < numStudents; ++i) {
        cout << "Enter details for student " << (i + 1) << ":\n";
        students[i].input();
    }

    // Find and display the topper
    Student topper = max(students, numStudents);

    cout << "\nTopper Information:\n";
    topper.display();

    return 0;
}
