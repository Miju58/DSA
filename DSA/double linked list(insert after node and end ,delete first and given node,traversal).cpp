#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) : data(data), next(NULL), prev(NULL) {}
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() : head(NULL) {}

    void insertAfter(Node* prev_node, int data) {
        if (prev_node == NULL) {
            cout << "The given previous node cannot be NULL" << endl;
            return;
        }

        Node* new_node = new Node(data);
        new_node->next = prev_node->next;
        new_node->prev = prev_node;

        if (prev_node->next != NULL)
            prev_node->next->prev = new_node;

        prev_node->next = new_node;
    }

    void deleteFirstNode() {
        if (head == NULL) {
            cout << "The list is empty, nothing to delete" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;

        if (head != NULL)
            head->prev = NULL;

        delete temp;
    }

    void insertAtEnd(int data) {
        Node* new_node = new Node(data);
        Node* last = head;

        if (head == NULL) {
            head = new_node;
            return;
        }

        while (last->next != NULL)
            last = last->next;

        last->next = new_node;
        new_node->prev = last;
    }

    void deleteAfter(Node* prev_node) {
        if (prev_node == NULL || prev_node->next == NULL) {
            cout << "The given previous node cannot be NULL or the last node" << endl;
            return;
        }

        Node* temp = prev_node->next;
        prev_node->next = temp->next;

        if (temp->next != NULL)
            temp->next->prev = prev_node;

        delete temp;
    }

    void traverse() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    Node* getHead() {
        return head;
    }
};

int main() {
    DoublyLinkedList dll;

    dll.insertAtEnd(10);
    dll.insertAtEnd(20);
    dll.insertAtEnd(30);
    dll.traverse();  // Output: 10 20 30

    dll.insertAfter(dll.getHead(), 15);
    dll.traverse();  // Output: 10 15 20 30

    dll.deleteFirstNode();
    dll.traverse();  // Output: 15 20 30

    dll.deleteAfter(dll.getHead());
    dll.traverse();  // Output: 15 30

    return 0;
}

