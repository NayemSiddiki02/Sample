#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *link;
    Node *prev;
    Node(int val)
    {
        this->val = val;
        this->link = NULL;
        this->prev = NULL;
    }
};

struct myStack
{
    Node *head = NULL;
    Node *tail = NULL;
    int sz = 0;
    
    void push(int val)
    {
        sz++;
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        newNode->prev = tail;
        tail->link = newNode;
        tail = tail->link;
    }
    
    void pop()
    {
        sz--;
        Node *deleteNode = tail;
        tail = tail->prev;
        if (tail == NULL)
        {
            head = NULL;
        }
        else
        {
            tail->link = NULL;
        }

        delete deleteNode;
    }

    int top()
    {
        return tail->val;
    }
    
    int size()
    {
        return sz;
    }

    bool empty()
    {
        return sz == 0;
    }
};

int main()
{
    myStack st;
    st.push(10);
    st.push(20);
    st.push(30);
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;

    return 0;
}
