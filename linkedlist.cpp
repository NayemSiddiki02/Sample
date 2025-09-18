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

// Function to print the data in the linked list
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

    // Function to delete the last node
Node* delete_last_node(Node* head) {
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

    return head; // Return the updated head
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

// Function to delete a node at a given position
void delete_at_position(Node** head, int position)
    {
        if (*head == nullptr)
    { // Check if the list is empty
        cout << "List is already empty!" << endl;
        return;
    }

    Node* current = *head; // Pointer to traverse the list
    Node* previous = *head; // Pointer to track the previous node

    // If the position is 1 (deleting the first node)
    if (position == 1)
    {
        *head = current->link; // Update head to the next node
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
    print_nodes(head);            // Print the nodes

    // Insert a node at the end
    insert_at_end(head, 90);
    cout << "After inserting at the end: ";
    print_nodes(head);

    // Insert a node at the beginning
    head = insert_at_beginning(head, 12);
    cout << "After inserting at the beginning: ";
    print_nodes(head);

    // Alternative Approach: pass head by reference
    //insert_at_beginning(head, 12); // No reassignment needed

    // Insert a node at position 3 with data 67
    insert_at_position(head, 3, 67);
    cout << "After inserting at position 3: ";
    print_nodes(head);

     // Delete the first node
    head = delete_first_node(head);

    // Print the linked list after deletion
    cout << "Linked list after deleting the first node: ";
    print_nodes(head);

    // Delete the last remaining node
    head = delete_last_node(head);

    // Print the linked list after deletion
    cout << "Linked list after deleting the last node: ";
    print_nodes(head);

    /*// Delete the last node
    head = delete_last_node(head);

    // Print the linked list after deletion
    cout << "Linked list after deleting the last node: ";
    print_nodes(head);*/

    // Delete node at position 2
    delete_at_position(&head, 2);

    // Print the linked list after deletion
    cout << "After deleting node at position 2 ";
    print_nodes(head);

    return 0; // Indicate successful execution
}
