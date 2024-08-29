#include "Queue.h"

int main() {
    int capacity;
    cout << "Enter the capacity of the queue: ";
    cin >> capacity;

    MyQueueNamespace::Queue<int> q(capacity);

    int choice, value;
    while (true) {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\nChoose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                cout << "Front element is: " << q.peek() << endl;
                break;
            case 4:
                q.display();
                break;
            case 5:
                exit(0);
            default:
                cout << "Invalid option! Try again." << endl;
        }
    }

    return 0;
}
