#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* link;
};

// Function to count the number of nodes
    int countNodes(Node* head)
    {
    int countt = 0;
    if (head == nullptr)
    {
        cout << "Linked list is empty" << endl;
        return 0; // Return 0 if the list is empty
    }
    Node* temp = head;
    while (temp != nullptr)
    {
        countt++;
        temp = temp->link;
    }
    cout << "Number of nodes: " << countt << endl;
    return countt;
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

    // Function calls
    countNodes(head);             // Count the nodes

    return 0;
}
