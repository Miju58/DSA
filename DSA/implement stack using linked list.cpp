#include <iostream>
using namespace std;

class Node {
	public:
    int data;
    Node* next;
    Node(int data){
    	this->data=data;
	}
};

class Stack {

public:
	Node* top;
    Stack() {
        top = NULL;
    }

    void push(int data) {
        Node* newNode = new Node(data);
        newNode->data = data;
        newNode->next = top;
        top = newNode;
        cout << data << " pushed to stack" << endl;
    }

    bool isEmpty() {
        return top == NULL;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow" << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        cout << temp->data << " popped from stack" << endl;
        delete temp;
    }

    int peek() {
        if (!isEmpty()) {
            return top->data;
        } else {
            cout << "Stack is empty" << endl;
            return -1;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        Node* temp = top;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
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

