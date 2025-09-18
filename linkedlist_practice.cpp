#include <iostream>
using namespace std;

struct Node
{
    int id;
    string name;
    double price;
    int quantity;
    string category;
    Node* link;
};

void insertproduct(Node*& head, int id, string name, double price, int quantity, string category)
{
    Node* temp = new Node();
    temp->id = id;
    temp->name = name;
    temp->price = price;
    temp->quantity = quantity;
    temp->category = category;
    temp->link = nullptr;

    if (head == nullptr)
    {
        head = temp;
        return;
    }

    Node* ptr = head;
    while (ptr->link != nullptr)
    {
        ptr = ptr->link;
    }
    ptr->link = temp;
}

void pricerange (Node* head)
{

    double minprice=head->price;
    double maxprice=head->price;

    Node* range = head;
    while (range!=nullptr)
    {
        if (range->price<minprice)
        {
            minprice=range->price;
        }
        if (range->price>maxprice)
        {
            maxprice=range->price;
        }
        range=range->link;
    }
    cout<<"MINIMUM PRICE: "<<minprice<<endl;
    cout<<"MAXIMUM PRICE: "<<maxprice<<endl;
}



void displayProducts(Node* head)
{
    Node* printing = head;

    while (printing != nullptr)
    {
        cout << "Product ID: " << printing->id << "; Name: " << printing->name
             << "; Price: " << printing->price << "; Quantity: " << printing->quantity
             << "; Category: " << printing->category << endl;
        printing = printing->link;
    }
}

int main()
{
    Node* head = nullptr;

    insertproduct(head, 120, "d", 9.22, 20, "stationery");
    insertproduct(head, 130, "a", 5.12, 530, "sfdfdf");
    insertproduct(head, 140, "b", 5.99, 150, "sty");
    insertproduct(head, 150, "c", 100.23, 54, "alalalalry");


    displayProducts(head);
    pricerange (head);

    return 0;
}
