#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
    	this->data=data;
		next=NULL;	
	}
};

class CircularLinkedList {
    

public:
	Node* last;
    CircularLinkedList(){
    	last=NULL;
	}

    void insertAfter(Node* prev_node, int data) {
        if (prev_node == NULL) return;

        Node* new_node = new Node(data);
        new_node->next = prev_node->next;
        prev_node->next = new_node;

        if (prev_node == last) last = new_node;
    }

    void deleteFirstNode() {
        if (last == NULL) return;

        Node* temp = last->next;

        if (last == last->next) {
            delete temp;
            last = NULL;
        } else {
            last->next = temp->next;
            delete temp;
        }
    }

    void insertAtEnd(int data) {
        Node* new_node = new Node(data);

        if (last == NULL) {
            last = new_node;
            last->next = last;
        } else {
            new_node->next = last->next;
            last->next = new_node;
            last = new_node;
        }
    }

    void deleteAfter(Node* prev_node) {
        if (prev_node == NULL || prev_node->next == last->next) return;

        Node* temp = prev_node->next;
        prev_node->next = temp->next;
        if (temp == last) last = prev_node;
        delete temp;
    }

    void traverse() {
        if (last == NULL) return;

        Node* temp = last->next;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != last->next);
        cout << endl;
    }
};

int main() {
    CircularLinkedList cll;

    // Example usage
    cll.insertAtEnd(10);
    cll.insertAtEnd(20);
    cll.insertAtEnd(30);
    cll.traverse();

    cll.insertAfter(cll.last->next, 15);  // Insert after the first node
    cll.traverse();

    cll.deleteFirstNode();
    cll.traverse();

    cll.deleteAfter(cll.last->next);  // Delete node after the first node
    cll.traverse();

    return 0;
}

