#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* link;
};

    // Function to delete the first node
    Node* delete_first_node(Node* head)
    {
    if (head == nullptr) { // Check if the list is empty
        cout << "The linked list is already empty." << endl;
        return nullptr;
    }

    Node* temp = head;     // Temporarily store the current head
    head = head->link;     // Move the head pointer to the next node
    delete temp;           // Free the memory of the original head
    cout << "First node deleted successfully." << endl;

    return head;           // Return the updated head
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

    // Delete the first node
    head = delete_first_node(head);

    // Print the linked list after deletion
    cout << "Linked list after deleting the first node: ";
    print_nodes(head);

    return 0;
    }
