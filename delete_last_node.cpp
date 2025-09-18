#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* link;
};

    // Function to delete the last node
void delete_last_node(Node* head) {
    if (head == nullptr) { // Case 1: List is empty
        cout << "List is already empty!" << endl;
    }
    else if (head->link == nullptr) { // Case 2: Only one node in the list
        delete head;   // Free the memory of the single node
        head = nullptr; // Set head to nullptr
    }
    else { // Case 3: More than one node in the list
        Node* temp = head;  // Pointer to traverse the list
        Node* temp2 = head; // Pointer to keep track of the second-to-last node

        // Traverse to the last node
        while (temp->link != nullptr) {
            temp2 = temp;        // Update temp2 to the current node
            temp = temp->link;   // Move temp to the next node
        }

        temp2->link = nullptr; // Update the second-to-last node's link to nullptr
        delete temp;           // Free the memory of the last node
        temp = nullptr;        // Set temp to nullptr for safety
    }

    // Return the updated head
}
    /*// Function to delete the last node
Node* delete_last_node(Node* head) {
    if (head == nullptr) { // Check if the list is empty
        cout << "The linked list is already empty." << endl;
        return nullptr;
    }

    if (head->link == nullptr) { // If there's only one node
        delete head;             // Free the memory of the single node
        cout << "Last node deleted successfully. The list is now empty." << endl;
        return nullptr;          // The new head is null
    }

    Node* temp = head; // Pointer to traverse the list

    // Traverse to the second-to-last node
    while (temp->link->link != nullptr) {
        temp = temp->link;
    }

    // Delete the last node
    delete temp->link;
    temp->link = nullptr; // Update the second-to-last node's link to null
    cout << "Last node deleted successfully." << endl;

    return head; // Return the updated head
} */

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

    // Delete the last remaining node
     delete_last_node(head);

    // Print the linked list after deletion
    cout << "Linked list after deleting the last node: ";
    print_nodes(head);

    /*// Delete the last node
    head = delete_last_node(head);

    // Print the linked list after deletion
    cout << "Linked list after deleting the last node: ";
    print_nodes(head);*/

    return 0;
    }
