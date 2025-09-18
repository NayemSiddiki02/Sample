#include <iostream>
using namespace std;

struct Node 
{
    int val;
    Node* link;
    Node* prev;

    Node(int val) 
    {
        this->val = val;
        this->link = NULL;
        this->prev = NULL;
    }
};

void insert_first_position(Node*& head, Node*& tail, int val) 
{
    Node* newNode = new Node(val);
    if (head == NULL) 
    {
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->link = head;
    head->prev = newNode;
    head = newNode;
}

void insert_last_node(Node*& head, Node*& tail, int val) 
{
    Node* newNode = new Node(val);
    if (tail == NULL) 
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->link = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void insert_at_position(Node* head, int pos, int val) 
{
    Node* newNode = new Node(val);
    Node* tmp = head;
    for (int i = 1; i <= pos - 1; i++) 
    {
        tmp = tmp->link;
    }
    newNode->link = tmp->link;
    tmp->link = newNode;
    if (newNode->link != NULL) 
    {
        newNode->link->prev = newNode;
    }
    newNode->prev = tmp;
}

void delete_first_node(Node*& head, Node*& tail) 
{
    if (head == NULL) return;
    Node* deleteNode = head;
    head = head->link;
    delete deleteNode;
    if (head == NULL)
    {
        tail = NULL;
        return;
    }
    head->prev = NULL;
}

void delete_last_node(Node*& head, Node*& tail) 
{
    if (tail == NULL) return;
    Node* deleteNode = tail;
    tail = tail->prev;
    delete deleteNode;
    if (tail == NULL) 
    {
        head = NULL;
        return;
    }
    tail->link = NULL;
}

void delete_at_position(Node* head, int pos) 
{
    Node* tmp = head;
    for (int i = 1; i <= pos - 1; i++) 
    {
        tmp = tmp->link;
    }
    Node* deleteNode = tmp->link;
    tmp->link = tmp->link->link;
    if (tmp->link != NULL) 
    {
        tmp->link->prev = tmp;
    }
    delete deleteNode;
}

void traverse(Node* head) 
{
    Node* tmp = head;
    while (tmp != NULL) 
    {
        cout << tmp->val << " ";
        tmp = tmp->link;
    }
    cout << endl;
}

bool search(Node* head, int val) 
{
    Node* tmp = head;
    while (tmp != NULL) 
    {
        if (tmp->val == val) return true;
        tmp = tmp->link;
    }
    return false;
}

int main() 
{
    Node* head = NULL;
    Node* tail = NULL;

    insert_first_position(head, tail, 10);
    insert_last_node(head, tail, 20);
    insert_first_position(head, tail, 5);
    insert_at_position(head, 2, 15);
    insert_last_node(head, tail, 25);

    cout << "List after insertions: ";
    traverse(head);

cout << "Search 15: ";
if (search(head, 15)) 
{
    cout << "Found";
} 
else 
{
    cout << "Not Found";
}
cout << endl;

cout << "Search 30: ";
if (search(head, 30)) {
    cout << "Found";
} else {
    cout << "Not Found";
}
cout << endl;


    delete_first_node(head, tail);
    delete_last_node(head, tail);
    delete_at_position(head, 2);

    cout << "List after deletions: ";
    traverse(head);

    return 0;
}
