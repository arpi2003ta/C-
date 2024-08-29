#include <iostream>
#include <string>

using namespace std;

class Student {
public:
    string name;
    int roll;
    int marks[3];

    static float totalMarks;
    static int studentCount;

    // Method to calculate total marks for the student
    int total() const {
        int total = 0;
        for (int i = 0; i < 3; ++i) {
            total += marks[i];
        }
        return total;
    }
};

// Initialize static members
float Student::totalMarks = 0.0;
int Student::studentCount = 0;

// Function to display student data
void display(const Student& student) {
    cout << "Name: " << student.name << "\n";
    cout << "Roll number: " << student.roll << "\n";
    cout << "Marks: ";
    for (int i = 0; i < 3; ++i) {
        cout << student.marks[i] << " ";
    }
    cout << "\n";
}

// Static function to calculate average marks of all students
float average() {
    if (Student::studentCount == 0) return 0.0;
    return Student::totalMarks / (Student::studentCount * 3);
}

// Static function to find the student with the highest total marks
Student max(Student students[], int n) {
    int maxIndex = 0;
    for (int i = 1; i < n; ++i) {
        if (students[i].total() > students[maxIndex].total()) {
            maxIndex = i;
        }
    }
    return students[maxIndex];
}

int main() {
    const int numStudents = 5;
    Student students[numStudents];

    // Input data for each student
    for (int i = 0; i < numStudents; ++i) {
        cout << "Enter details for student " << i + 1 << ":\n";
        cout << "Enter name: ";
        cin >> students[i].name;
        cout << "Enter roll number: ";
        cin >> students[i].roll;
        cout << "Enter marks for three subjects: ";
        for (int j = 0; j < 3; ++j) {
            cin >> students[i].marks[j];
            Student::totalMarks += students[i].marks[j];
        }
        Student::studentCount++;
    }

    // Display data for each student
    cout << "\nDisplaying student details:\n";
    for (int i = 0; i < numStudents; ++i) {
        display(students[i]);
        cout << "Total marks: " << students[i].total() << "\n\n";
    }

    // Find and display the topper
    Student topper = max(students, numStudents);
    cout << "Topper's details:\n";
    display(topper);
    cout << "Total marks: " << topper.total() << "\n\n";

    // Display average marks
    cout << "Average marks of all students: " << average() << "\n";

    return 0;
}
