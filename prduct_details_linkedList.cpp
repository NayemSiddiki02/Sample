#include <iostream>
#include <string>
using namespace std;

// Node structure for the linked list
struct Node
{
    int id;
    string name;
    float price;
    int stock_quantity;
    string category;
    Node* link; // Renamed 'next' to 'link'
};

// Function to insert a new product node into the linked list
void insert(Node*& head, int id, string name, float price, int stock_quantity, string category)
{
    Node* newNode = new Node{id, name, price, stock_quantity, category, nullptr};
    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->link!=nullptr)
    { // Traverse using 'link'
        temp = temp->link;
    }
    temp->link = newNode; // Connect the new node using 'link'
}

// Function to calculate price difference
float priceDifference(Node* head)
{
    if (head == nullptr)
    {
        return 0;
    }

    float maxPrice = head->price, minPrice = head->price;
    Node* temp = head;
    while (temp!=nullptr)
        {
        if (temp->price > maxPrice)
        {
            maxPrice = temp->price;
        }
        if (temp->price < minPrice)
        {
            minPrice = temp->price;
        }
        temp = temp->link; // Move to the next node using 'link'
    }
    return maxPrice - minPrice;
}

// Function to calculate total stock value
float totalStockValue(Node* head)
{
    float totalValue = 0;
    Node* temp = head;
    while (temp!=nullptr)
    {
        totalValue = totalValue + temp->price * temp->stock_quantity;
        temp = temp->link; // Move to the next node using 'link'
    }
    return totalValue;
}

// Function to find and print products with price <= 50
void findAffordableProducts(Node* head)
{
    Node* temp = head;
    cout << "Products with price <= 50: ";
    while (temp!=nullptr)
    {
        if (temp->price <= 50)
        {
            cout << temp->name << " ";
        }
        temp = temp->link; // Move to the next node using 'link'
    }
    cout << endl;
}

// Function to display product details
void displayProducts(Node* head)
{
    Node* temp = head;
    while (temp!=nullptr)
        {
        cout << "ID: " << temp->id << ", Name: " << temp->name << ", Price: $" << temp->price
             << ", Stock: " << temp->stock_quantity << ", Category: " << temp->category << endl;
        temp = temp->link; // Move to the next node using 'link'
    }
}

int main()
{
    Node* head = nullptr;

    // Insert products into the linked list
    insert(head, 101, "Laptop", 799.99, 10, "Electronics");
    insert(head, 102, "Notebook", 2.99, 100, "Stationery");
    insert(head, 103, "Pen", 1.50, 200, "Stationery");
    insert(head, 104, "Headphones", 49.99, 25, "Electronics");

    // Display all product records
    cout << "Product Records:" << endl;
    displayProducts(head);

    // Calculate and display price difference
    cout << "Price difference between the most expensive and the cheapest product: $" << priceDifference(head) << endl;

    // Calculate and display total stock value
    cout << "Total stock value of all products: $" << totalStockValue(head) << endl;

    // Find and display affordable products
    findAffordableProducts(head);

    return 0;
}
