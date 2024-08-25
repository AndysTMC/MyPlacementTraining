#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

int main()
{
    Node *head = nullptr; // Initialize the head of the list to nullptr

    // For demonstration purposes, let's create a sample linked list:
    // Creating nodes
    Node *first = new Node();
    Node *second = new Node();
    Node *third = new Node();
    // Assigning data
    first->data = 1;
    second->data = 2;
    third->data = 3;
    // Connecting nodes
    head = first;
    first->next = second;
    second->next = third;
    third->next = nullptr;

    // Initialize k to a value for which we want to search
    int k = 2;

    // Finding the node with value k
    Node *temp = head;
    while (temp != nullptr && temp->data != k)
    {
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        cout << "Value " << k << " not found in the list." << endl;
        return 0;
    }

    // Reverse the linked list until the node with value k
    Node *prev = nullptr;
    Node *current = head;
    Node *next = nullptr;

    while (current != nullptr && current->data != k)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    // Reconnect the rest of the list
    if (current != nullptr)
    {
        head->next = current; // Reconnect the reversed part with the remaining list
    }
    else
    {
        head->next = nullptr; // If k is at the end, make the next of last reversed node null
    }

    head = prev;

    // Printing the list to check the result
    Node *itr = head;
    while (itr != nullptr)
    {
        cout << itr->data << " ";
        itr = itr->next;
    }
    cout << endl;

    return 0;
}
