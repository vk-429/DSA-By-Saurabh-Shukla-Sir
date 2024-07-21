#include <iostream>
using namespace std;
// Class representing a node in the linked list
class Node {
public:
    int data;
    Node* next;
    Node(){cout<<"Default constructor Called\n";}
    Node(int value) {
        data = value;
        next = NULL;
    }
};

// Class representing a singly linked list
class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    // Function to insert a new node at the beginning of the linked list
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Function to display the linked list
    void displayList() {
        Node* current = head;

        while (current != NULL) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "NULL" << std::endl;
    }
};

int main() {
    // Create an instance of the LinkedList class
    LinkedList myList;

    // Insert nodes at the beginning of the linked list
    myList.insertAtBeginning(3);
    myList.insertAtBeginning(2);
    myList.insertAtBeginning(1);

    // Display the linked list
    myList.displayList();

    return 0;
}
