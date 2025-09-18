#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* link;    //self referencing
};

void searching_data (Node* head, int item)
{
    Node* ptr = head;

    if(head==nullptr)
    {
        cout<<"THE LINKED LIST IS EMPTY."<<endl;
        return;
    }

    int position = 0;
    while (ptr != nullptr)
    {
        position++;
    if (ptr->data==item)
    {
        cout<<"found in "<<position<<endl;
    }
    ptr = ptr->link;
    }
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
    searching_data (head, 98);

    return 0;
}
