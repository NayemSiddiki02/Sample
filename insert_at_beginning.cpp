#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* link;
};

// Function to insert a node at the beginning
    Node* insert_at_beginning(Node* head, int data) {
    Node* temp = new Node(); // Allocate memory for new node
    temp->data = data;
    temp->link = head; // Point the new node to the current head
    head = temp;       // Update the head to the new node
    return head;       // Return the updated head
    }

    // Alternative Approach: pass head by reference
    /*void insert_at_beginning(Node*& head, int data)
    {
    Node* temp = new Node();
    temp->data = data;
    temp->link = head;
    head = temp; // Update the head directly
    }*/

    // Function to print/ the data in the linked list
void print_nodes(Node* head)
{
    if (head == nullptr)
    {
        cout << "Linked list is empty" << endl;
        return;
    }

    Node* ptr = head;
    cout << "Linked list values: ";
    while (ptr != nullptr)
    {
        cout << ptr->data << " ";
        ptr = ptr->link;
    }
    cout << endl;
}

    int main()
{
    // Initialize the linked list
    Node* head = new Node();
    head->data = 45;
    head->link = nullptr;

    Node* current = new Node();
    current->data = 98;
    current->link = nullptr;
    head->link = current; // Link the first node to the second node

    current = new Node();
    current->data = 3;
    current->link = nullptr;
    head->link->link = current; // Link the second node to the third node

    // Insert a node at the beginning
    head = insert_at_beginning(head, 12);
    cout << "After inserting at the beginning: ";
    print_nodes(head);

    // Alternative Approach: pass head by reference
    //insert_at_beginning(head, 12); // No reassignment needed


    return 0;
}
