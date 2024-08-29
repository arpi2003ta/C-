#include <iostream>
using namespace std;

struct Time {
    int hour;
    int minute;
    int second;

    // Member function to add two Time variables
    Time add(const Time& t) const {
        Time result;
        result.second = second + t.second;
        result.minute = minute + t.minute + result.second / 60;
        result.hour = hour + t.hour + result.minute / 60;
        result.second %= 60;
        result.minute %= 60;
        result.hour %= 24; // assuming 24-hour time format
        return result;
    }

    // Member function to subtract two Time variables
    Time subtract(const Time& t) const {
        Time result;
        int totalSeconds1 = hour * 3600 + minute * 60 + second;
        int totalSeconds2 = t.hour * 3600 + t.minute * 60 + t.second;
        int totalSeconds = totalSeconds1 - totalSeconds2;

        if (totalSeconds < 0) {
            totalSeconds += 24 * 3600; // adjust for negative difference by adding a full day in seconds
        }

        result.hour = totalSeconds / 3600;
        result.minute = (totalSeconds % 3600) / 60;
        result.second = totalSeconds % 60;
        return result;
    }

    // Function to display time in HH:MM:SS format
    void display() const {
        cout << (hour < 10 ? "0" : "") << hour << ":"
             << (minute < 10 ? "0" : "") << minute << ":"
             << (second < 10 ? "0" : "") << second << endl;
    }
};

int main() {
    Time t1, t2, t3, t4;

    // Input first time
    cout << "Enter first time (HH MM SS): ";
    cin >> t1.hour >> t1.minute >> t1.second;

    // Input second time
    cout << "Enter second time (HH MM SS): ";
    cin >> t2.hour >> t2.minute >> t2.second;

    // Add times
    t3 = t1.add(t2);
    cout << "Addition of two times: ";
    t3.display();

    // Subtract times
    t4 = t1.subtract(t2);
    cout << "Subtraction of two times: ";
    t4.display();

    return 0;
}