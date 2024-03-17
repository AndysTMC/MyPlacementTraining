//Print all the elements in order from the point of intersection if the cycle exists in the linked list
//if the list is sorted Now remove the duplicates from the list
//Find the intersection point of two linked lists
//Find the starting point of the cycle in the linked list


#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

void insert(Node** head, int data){
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = *head;
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
        cout << "Invalid position!" << endl;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void insertAtLast(Node** head, int data) {
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = nullptr;

    if (*head == nullptr) {
        *head = new_node;
        return;
    }

    Node* temp = *head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = new_node;
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
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;
}

void deleteAtFirst(Node** head) {
    if (*head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = *head;
    *head = (*head)->next;
    delete temp;
}

void deleteAfterNth(Node* head, int n) {
    Node* temp = head;
    int count = 1;

    while (temp != nullptr && count < n) {
        temp = temp->next;
        count++;
    }

    if (temp == nullptr || temp->next == nullptr) {
        cout << "Invalid position!" << endl;
        return;
    }

    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;
}

void printList(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void reverseList(Node** head){
    Node* prev = NULL;
    Node* current = *head;
    Node* next = NULL;

    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void cycleDetection(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            cout << "Cycle detected!" << endl;
            return;
        }
    }
    cout << "No cycle detected!" << endl;
}

Node *getIntersectionNode(Node *headA, Node *headB) {
    auto getLength = [](Node *head) {
        int length = 0;
        while (head) {
            length++;
            head = head->next;
        }
        return length;
    };
    
    int lenA = getLength(headA);
    int lenB = getLength(headB);
    
    while (lenA > lenB) {
        headA = headA->next;
        lenA--;
    }
    while (lenB > lenA) {
        headB = headB->next;
        lenB--;
    }
    
    while (headA != headB) {
        headA = headA->next;
        headB = headB->next;
    }
    
    return headA;
}

int main(){
    Node* head = NULL;
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
    deleteAtFirst(&head);
    deleteAfterNth(head, 5);
    printList(head);
    return 0;
}