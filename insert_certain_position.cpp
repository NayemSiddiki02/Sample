#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* link;
};

    // Function to insert a node at a certain position
void insert_at_position(Node* head, int position, int data)
{
    if (position < 1)
    {
        cout << "Invalid position. Position should be >= 1." << endl;
        return;
    }

    Node* temp = new Node(); // Allocate memory for new node
    temp->data = data;

    // Inserting at position 1 (at the beginning)
    if (position == 1)
    {
        temp->link = head;
        head = temp;
        return;
    }

    Node* current = head;
    int current_position = 1;

    // Traverse to the position just before the target
    while (current != nullptr && current_position < position - 1)
    {
        current = current->link;
        current_position++;
    }

    // Check if the position is valid
    if (current == nullptr)
    {
        cout << "Invalid position. The linked list has fewer nodes than " << position << "." << endl;
        delete temp; // Free memory if the position is invalid
        return;
    }

    // Insert the node at the desired position
    temp->link = current->link;
    current->link = temp;
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

    // Insert a node at position 3 with data 67
    insert_at_position(head, 3, 67);
    cout << "After inserting at position 3: ";
    print_nodes(head);


    return 0;
}
