#include <iostream>

using namespace std;

struct Node {
    Node* prev;
    int data;
    Node* next;
};

// Function to add a node to an empty list
Node* addToEmpty(Node* head, int data) {
    Node* temp = new Node();
    temp->prev = nullptr;
    temp->data = data;
    temp->next = nullptr;
    head = temp;
    return head;
}

// Function to add a node at the beginning of the list
Node* addAtBeg(Node* head, int data) {
    Node* temp = new Node();
    temp->prev = nullptr;
    temp->data = data;
    temp->next = head;

    if (head != nullptr) {
        head->prev = temp;
    }
    head = temp;
    return head;
}

// Function to add a node at the end of the list
Node* addAtEnd(Node* head, int data) {
    Node* temp = new Node();
    temp->prev = nullptr;
    temp->data = data;
    temp->next = nullptr;

    if (head == nullptr) {
        return temp;
    }

    Node* tp = head;
    while (tp->next != nullptr) {
        tp = tp->next;
    }

    tp->next = temp;
    temp->prev = tp;
    return head;
}

// Function to add a node after a given position in the list
Node* addAfterPos(Node* head, int data, int position) {
    if (head == nullptr || position < 1) {
        cout << "Invalid operation or position!" << endl;
        return head;
    }

    Node* newp = new Node();
    newp->data = data;
    newp->next = nullptr;
    newp->prev = nullptr;

    Node* temp = head;

    // Traverse to the desired position
    while (position != 1 && temp->next != nullptr) {
        temp = temp->next;
        position--;
    }

    // If at the end of the list
    if (temp->next == nullptr) {
        temp->next = newp;
        newp->prev = temp;
    } 
    // Insert between nodes
    else {
        Node* temp2 = temp->next;
        temp->next = newp;
        temp2->prev = newp;
        newp->next = temp2;
        newp->prev = temp;
    }

    return head;
}

// Function to print the elements of the list
void printList(Node* head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* current = head;
    cout << "List elements: ";
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    int position = 2;

    // Adding elements to the list and printing the state after each operation
    cout << "Adding 45 to an empty list:" << endl;
    head = addToEmpty(head, 45);
    printList(head);

    cout << "Adding 34 at the beginning:" << endl;
    head = addAtBeg(head, 34);
    printList(head);

    cout << "Adding 9 at the end:" << endl;
    head = addAtEnd(head, 9);
    printList(head);

    cout << "Adding 25 after position 2:" << endl;
    head = addAfterPos(head, 25, position);
    printList(head);

    return 0;
}
