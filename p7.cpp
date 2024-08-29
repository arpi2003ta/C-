#include <iostream>
using namespace std;

class Time {
private:
    int hour, minute, second;

public:
    // Constructor to initialize time
    Time(int h = 0, int m = 0, int s = 0) : hour(h), minute(m), second(s) {}

    // Function to add two Time objects
    Time add(const Time& t) const;

    // Function to subtract two Time objects
    Time subtract(const Time& t) const;

    // Function to display time
    void display() const;

    // Setters to set the time
    void setTime(int h, int m, int s);
};

Time Time::add(const Time& t) const {
    Time result;
    result.second = second + t.second;
    result.minute = minute + t.minute + result.second / 60;
    result.hour = hour + t.hour + result.minute / 60;
    result.minute %= 60;
    result.second %= 60;
    result.hour %= 24; // To keep it in 24-hour format
    return result;
}

Time Time::subtract(const Time& t) const {
    Time result;
    int totalSeconds1 = hour * 3600 + minute * 60 + second;
    int totalSeconds2 = t.hour * 3600 + t.minute * 60 + t.second;
    int totalSecondsResult = totalSeconds1 - totalSeconds2;

    if (totalSecondsResult < 0) {
        totalSecondsResult += 24 * 3600; // To handle negative time differences
    }

    result.hour = totalSecondsResult / 3600;
    totalSecondsResult %= 3600;
    result.minute = totalSecondsResult / 60;
    result.second = totalSecondsResult % 60;

    return result;
}

void Time::display() const {
    cout << (hour < 10 ? "0" : "") << hour << ":"
         << (minute < 10 ? "0" : "") << minute << ":"
         << (second < 10 ? "0" : "") << second << endl;
}

void Time::setTime(int h, int m, int s) {
    hour = h;
    minute = m;
    second = s;
}

int main() {
    Time t1, t2;
    int h, m, s;

    cout << "Enter Time 1 (hour minute second): ";
    cin >> h >> m >> s;
    t1.setTime(h, m, s);

    cout << "Enter Time 2 (hour minute second): ";
    cin >> h >> m >> s;
    t2.setTime(h, m, s);

    Time tAdd = t1.add(t2);
    Time tSubtract = t1.subtract(t2);

    cout << "Time 1: ";
    t1.display();
    cout << "Time 2: ";
    t2.display();
    cout << "Time 1 + Time 2: ";
    tAdd.display();
    cout << "Time 1 - Time 2: ";
    tSubtract.display();

    return 0;
}
