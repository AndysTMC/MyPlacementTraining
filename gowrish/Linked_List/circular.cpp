#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;
};

void insert(Node** head, int data){
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = *head;
    new_node->prev = nullptr;
    if(*head != nullptr){
        (*head)->prev = new_node;
    }
    *head = new_node;
}

void insertAfterNth(Node* head, int n, int data) {
    Node* newNode = new Node();
    newNode->data = data;

    Node* temp = head;
    int count = 1;

    while (temp != nullptr && count < n) {
        temp = temp->next;
        count++;
    }

    if (temp == nullptr) {
        cout<<"Invalid position!"<<endl;
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    if(temp->next != nullptr){
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

void insertAtLast(Node** head, int data) {
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = nullptr;
    if(*head == nullptr){
        new_node->prev = nullptr;
        *head = new_node;
        return;
    }
    Node* temp = *head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = new_node;
    new_node->prev = temp;
}

void deleteAtLast(Node** head) {
    if (*head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    if ((*head)->next == nullptr) {
        delete *head;
        *head = nullptr;
        return;
    }

    Node* temp = *head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->prev->next = nullptr;
    delete temp;
}

void printList(Node* node) {
    Node* last;
    cout << "Traversal in forward direction: " << endl;
    while (node != nullptr) {
        cout << node->data << " ";
        last = node;
        node = node->next;
    }
    cout << endl;
    cout << "Traversal in reverse direction: " << endl;
    while (last != nullptr) {
        cout << last->data << " ";
        last = last->prev;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);
    insert(&head, 6);
    insert(&head, 7);
    insert(&head, 8);
    insert(&head, 9);
    insert(&head, 10);
    insertAfterNth(head, 5, 11);
    insertAtLast(&head, 12);
    deleteAtLast(&head);
    printList(head);
    return 0;
}