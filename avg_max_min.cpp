#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* link;
};

// Function to calculate the average of the linked list
double calculateAverage(Node* head) {
    if (head == nullptr) {
        cout << "The linked list is empty." << endl;
        return 0.0;
    }

    int sum = 0, count = 0;
    Node* current = head;

    while (current != nullptr) {
        sum += current->data;
        count++;
        current = current->link;
    }

    return (double)sum / count;
}

// Function to find the maximum value in the linked list
int findMaximum(Node* head) {
    if (head == nullptr) {
        cout << "The linked list is empty." << endl;
        return INT_MIN; // Indicates no valid maximum
    }

    int maxValue = head->data;
    Node* current = head;

    while (current != nullptr) {
        if (current->data > maxValue) {
            maxValue = current->data;
        }
        current = current->link;
    }

    return maxValue;
}

// Function to find the minimum value in the linked list
int findMinimum(Node* head) {
    if (head == nullptr) {
        cout << "The linked list is empty." << endl;
        return INT_MAX; // Indicates no valid minimum
    }

    int minValue = head->data;
    Node* current = head->link;

    while (current != nullptr) {
        if (current->data < minValue) {
            minValue = current->data;
        }
        current = current->link;
    }

    return minValue;
}

// Function to print the linked list
void printNodes(Node* head) {
    if (head == nullptr) {
        cout << "Linked list is empty" << endl;
        return;
    }

    Node* ptr = head;
    cout << "Linked list values: ";
    while (ptr != nullptr) {
        cout << ptr->data << " ";
        ptr = ptr->link;
    }
    cout << endl;
}

int main() {
    // Initialize the linked list
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

    printNodes(head);

    // Calculate and print the average
    double avg = calculateAverage(head);
    cout << "Average value: " << avg << endl;

    // Find and print the maximum
    int maxVal = findMaximum(head);
    cout << "Maximum value: " << maxVal << endl;

    // Find and print the minimum
    int minVal = findMinimum(head);
    cout << "Minimum value: " << minVal << endl;

    return 0;
}
