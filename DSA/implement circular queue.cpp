#include <iostream>
using namespace std;

class CircularQueue {
private:
    int front, rear, size;
    int* queue;
    int capacity;

public:
    CircularQueue(int capacity) {
        this->capacity = capacity;
        front = rear = -1;
        queue = new int[capacity];
    }

    ~CircularQueue() {
        delete[] queue;
    }

    void enqueue(int data) {
        if ((front == 0 && rear == capacity - 1) || (rear == (front - 1) % (capacity - 1))) {
            cout << "Queue overflow" << endl;
            return;
        }
        if (front == -1) {
            front = rear = 0;
        } else if (rear == capacity - 1 && front != 0) {
            rear = 0;
        } else {
            rear++;
        }
        queue[rear] = data;
        cout << data << " enqueued to queue" << endl;
    }

    void dequeue() {
        if (front == -1) {
            cout << "Queue underflow" << endl;
            return;
        }
        cout << queue[front] << " dequeued from queue" << endl;

        if (front == rear) {
            front = rear = -1;
        } else if (front == capacity - 1) {
            front = 0;
        } else {
            front++;
        }
    }

    void display() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return;
        }
        if (rear >= front) {
            for (int i = front; i <= rear; i++) {
                cout << queue[i] << " ";
            }
        } else {
            for (int i = front; i < capacity; i++) {
                cout << queue[i] << " ";
            }
            for (int i = 0; i <= rear; i++) {
                cout << queue[i] << " ";
            }
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    cout << "Queue elements are: ";
    q.display();

    q.dequeue();
    q.dequeue();

    cout << "Queue elements after dequeue operations are: ";
    q.display();

    q.enqueue(60);
    q.enqueue(70);

    cout << "Queue elements after enqueue operations are: ";
    q.display();

    return 0;
}

