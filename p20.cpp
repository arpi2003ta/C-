#include <iostream>
using namespace std;

class Employee {
protected:
    int emp_id;
    string name;

public:
    void set_data(int a, string b) {
        emp_id = a;
        name = b;
    }

    int get_emp_id() { return emp_id; }
    string get_name() { return name; }

    void admin_work() {
        cout << "Name: " << name << "  ID: " << emp_id << endl;
    }
};

class Faculty : virtual public Employee {
public:
    void teach_theory() {
        cout << "Teaching C++" << endl;
    }

    void research() {
        cout << "Researching on VLSI" << endl;
    }
};

class Tech_Assistant : virtual public Employee {
public:
    void teach_lab() {
        cout << "Teaching all labs" << endl;
    }
};

class Instructor : public Faculty, public Tech_Assistant {
public:
    void get_details() {
        cout << "Instructor Details:\n";
        cout << "Name: " << name << "  ID: " << emp_id << endl;
    }
};

int main() {
    // Using Faculty pointer to Instructor object
    Faculty* obj = new Instructor;
    obj->teach_theory();
    obj->research();
    obj->set_data(120, "XYZ");
    obj->admin_work();
    cout << endl;

    // Using Tech_Assistant pointer to Instructor object
    Tech_Assistant* obj2 = new Instructor;
    obj2->teach_lab();
    obj2->set_data(200, "ABC");
    obj2->admin_work();
    cout << endl;

    // Using Instructor object
    Instructor* obj3 = new Instructor;
    obj3->teach_theory();
    obj3->research();
    obj3->teach_lab();
    obj3->set_data(456, "PQR");
    obj3->admin_work();
    obj3->get_details();
    cout << endl;

    return 0;
}
