#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* link;
};

// Function to insert a node at the end
void insert_at_end(Node* head, int data)
{
    Node* ptr = head;
    Node* temp = new Node(); // Allocate memory for new node
    temp->data = data;
    temp->link = nullptr;

    while (ptr->link != nullptr)
        {
        ptr = ptr->link;
    }
    ptr->link = temp;
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

    // Insert a node at the end
    insert_at_end(head, 90);
    cout << "After inserting at the end: ";
    print_nodes(head);

    return 0;
}
