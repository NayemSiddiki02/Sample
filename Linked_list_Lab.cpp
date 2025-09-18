#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* link;
};

//.......................................................................
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

//.......................................................................
void insert_at_end(Node* head, int data)
{
    Node* ptr = head;
    Node* temp = new Node();
    temp->data = data;
    temp->link = nullptr;

    while (ptr->link != nullptr)
        {
        ptr = ptr->link;
    }
    ptr->link = temp;
}

//.......................................................................
    Node* insert_at_beginning(Node* head, int data) 
    {
    Node* temp = new Node(); 
    temp->data = data;
    temp->link = head; 
    head = temp;       
    return head;      
    }

//.......................................................................
void insert_at_position(Node* head, int position, int data)
{
    if (position < 1)
    {
        cout << "Invalid position. Position should be >= 1." << endl;
        return;
    }

    Node* temp = new Node();
    temp->data = data;

    if (position == 1)
    {
        temp->link = head;
        head = temp;
        return;
    }

    Node* current = head;
    int current_position = 1;

    while (current != nullptr && current_position < position - 1)
    {
        current = current->link;
        current_position++;
    }

    temp->link = current->link;
    current->link = temp;
}

//.......................................................................
    Node* delete_first_node(Node* head)
    {
    if (head == nullptr) 
    { 
        cout << "The linked list is empty." << endl;
        return nullptr;
    }

    Node* temp = head;     
    head = head->link;     
    delete temp;         
    cout << "First node deleted successfully." << endl;

    return head;
}

//.......................................................................
Node* delete_last_node(Node* head) 
{
    if (head == nullptr) 
    { 
        cout << "List is already empty!" << endl;
    }
    else if (head->link == nullptr) 
    { 
        delete head;   
        head = nullptr; 
    }
    else 
    { 
        Node* temp = head;  
        Node* temp2 = head;

        while (temp->link != nullptr) 
        {
            temp2 = temp;        
            temp = temp->link;   
        }

        temp2->link = nullptr; 
        delete temp;           
        temp = nullptr;        
    }

    return head; 
}

//.......................................................................
void delete_at_position(Node** head, int position)
    {
        if (*head == nullptr)
    { 
        cout << "List is already empty!" << endl;
        return;
    }

    Node* current = *head;
    Node* previous = *head;
    if (position == 1)
    {
        *head = current->link; 
        delete current;       
        cout << "Node at position " << position << " deleted successfully!" << endl;
        return;
    }

    while (position != 1 && current != nullptr)
    {
        previous = current;      
        current = current->link;  
        position--;      
    }

    previous->link = current->link;
    delete current; 
    cout << "Node at position " << position + 1 << " deleted successfully!" << endl;
}

//.......................................................................
int main()
{
    Node* head = new Node();
    head->data = 45;
    head->link = nullptr;

    Node* current = new Node();
    current->data = 98;
    current->link = nullptr;
    head->link = current; 

    current = new Node();
    current->data = 3;
    current->link = nullptr;
    head->link->link = current;

    insert_at_end(head, 90);
    cout << "After inserting at the end: ";
    print_nodes(head);

    head = insert_at_beginning(head, 12);
    cout << "After inserting at the beginning: ";
    print_nodes(head);

    insert_at_position(head, 3, 67);
    cout << "After inserting at position 3: ";
    print_nodes(head);

    head = delete_first_node(head);

    cout << "Linked list after deleting the first node: ";
    print_nodes(head);

    head = delete_last_node(head);

    cout << "Linked list after deleting the last node: ";
    print_nodes(head);

    delete_at_position(&head, 2);

    cout << "After deleting node at position 2 ";
    print_nodes(head);

    return 0;
}