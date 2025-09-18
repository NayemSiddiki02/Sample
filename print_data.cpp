#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* link; 
};

Node* insert_node (Node* head, int data)
{
    Node* ptr = head;
    Node* temp = new Node();
    temp->data = data;
    temp->link = nullptr;

    if (head == nullptr) 
    {
        head = temp;
        return head; 
    }

    while (ptr->link != nullptr)
        {
        ptr = ptr->link;
    }
    ptr->link = temp;
    return head;
}

void print_nodes(Node* head)
{
    if (head == nullptr)
    {
        //cout << "Linked list is empty" << endl;
        return;
    }

    Node* ptr = head;
    //cout << "Linked list values: ";
    while (ptr != nullptr)
    {
        cout << ptr->data << " ";
        ptr = ptr->link;
    }
    cout << endl;
}

int main()
{
    Node* head = nullptr;
    int n, value;

    // cout << "Enter the number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        //cout << "Enter value for node " << (i + 1) << ": ";
        cin >> value;
        head = insert_node(head, value);
    }

    print_nodes(head);

    return 0;

}
