#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

namespace MyQueueNamespace {

    template <typename T>
    class Queue {
    private:
        T* arr;
        int front, rear, capacity, count;

    public:
        Queue(int size);
        ~Queue();
        void enqueue(T item);
        void dequeue();
        T peek();
        int size();
        bool isEmpty();
        bool isFull();
        void display();
    };

    template <typename T>
    Queue<T>::Queue(int size) {
        arr = new T[size];
        capacity = size;
        front = 0;
        rear = -1;
        count = 0;
    }

    template <typename T>
    Queue<T>::~Queue() {
        delete[] arr;
    }

    template <typename T>
    void Queue<T>::enqueue(T item) {
        if (isFull()) {
            cout << "Queue is full, cannot enqueue " << item << endl;
            return;
        }

        rear = (rear + 1) % capacity;
        arr[rear] = item;
        count++;
        cout << "Enqueued " << item << ": ";
        display();
    }

    template <typename T>
    void Queue<T>::dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty, cannot dequeue" << endl;
            return;
        }

        cout << "Dequeued " << arr[front] << ": ";
        front = (front + 1) % capacity;
        count--;
        display();
    }

    template <typename T>
    T Queue<T>::peek() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            exit(EXIT_FAILURE);
        }
        return arr[front];
    }

    template <typename T>
    int Queue<T>::size() {
        return count;
    }

    template <typename T>
    bool Queue<T>::isEmpty() {
        return (count == 0);
    }

    template <typename T>
    bool Queue<T>::isFull() {
        return (count == capacity);
    }

    template <typename T>
    void Queue<T>::display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue: ";
        for (int i = 0; i < count; i++) {
            cout << arr[(front + i) % capacity] << " ";
        }
        cout << endl;
    }

}  // namespace MyQueueNamespace

#endif  // QUEUE_H
