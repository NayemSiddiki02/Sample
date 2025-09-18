#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* link;
};

// Function to delete a node at a given position
void delete_at_position(Node* head, int position)
    {
        if (head == nullptr)
    { // Check if the list is empty
        cout << "List is already empty!" << endl;
        return;
    }

    Node* current = head; // Pointer to traverse the list and for delete
    Node* previous = head; // Pointer to track the previous node

    // If the position is 1 (deleting the first node)
    if (position == 1)
    {
        head = current->link; // Update head to the next node
        delete current;        // Free memory of the first node
        cout << "Node at position " << position << " deleted successfully!" << endl;
        return;
    }

    // Traverse to the node at the given position
    while (position != 1 && current != nullptr)
    {
        previous = current;       // Keep track of the previous node
        current = current->link;  // Move to the next node
        position--;               // Decrease position counter
    }

    // Update the link of the previous node
    previous->link = current->link;
    delete current; // Free memory of the deleted node
    cout << "Node at position " << position + 1 << " deleted successfully!" << endl;
}

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

    // Delete node at position 2
    delete_at_position(head, 2);

    // Print the linked list after deletion
    cout << "After deleting node at position 2 ";
    print_nodes(head);

    return 0;
    }
