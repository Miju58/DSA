#include <iostream>
using namespace std;

class Stack {
private:
    int top;
    int arr[100];
    int capacity;

public:
    Stack(int size = 100) {
        top = -1;
        capacity = size;
    }

    void push(int x) {
        if (top == capacity - 1) {
            cout << "Stack overflow" << endl;
            return;
        }
        arr[++top] = x;
        cout << x << " pushed to stack" << endl;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack underflow" << endl;
            return;
        }
        cout << arr[top--] << " popped from stack" << endl;
    }

    int peek() {
        if (top != -1) {
            return arr[top];
        } else {
            cout << "Stack is empty" << endl;
            return -1;
        }
    }

    bool isEmpty() {
        return top == -1;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Stack elements are: ";
    s.display();

    cout << "Top element is: " << s.peek() << endl;

    s.pop();
    s.pop();

    cout << "Stack elements after pop operations are: ";
    s.display();

    cout << "Top element is: " << s.peek() << endl;

    return 0;
}

