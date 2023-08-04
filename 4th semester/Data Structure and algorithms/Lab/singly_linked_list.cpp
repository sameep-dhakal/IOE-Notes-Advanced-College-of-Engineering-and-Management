#include <iostream>
#include<stdlib.h>
using namespace std;

// Linked List Node
struct Node {
    int info;
    Node* link;
};

Node* start = nullptr;

// Function to create list with n nodes initially
void createList() {
    if (start == nullptr) {
        int n;
        cout << "Enter the number of nodes: ";
        cin >> n;

        if (n != 0) {
            int data;
            Node* newnode;
            Node* temp;

            newnode = new Node;
            start = newnode;
            temp = start;

            cout << "Enter number to be inserted: ";
            cin >> data;
            start->info = data;

            for (int i = 2; i <= n; i++) {
                newnode = new Node;
                temp->link = newnode;

                cout << "Enter number to be inserted: ";
                cin >> data;
                newnode->info = data;
                temp = temp->link;
            }
        }

        cout << "The list is created\n";
    }
    else {
        cout << "The list is already created\n";
    }
}

// Function to traverse the linked list
void traverse() {
    Node* temp;

    // List is empty
    if (start == nullptr)
        cout << "List is empty\n";
    else {
        temp = start;
        while (temp != nullptr) {
            cout << temp->info << "\t";
            temp = temp->link;
        }
    }
}

// Function to insert at the front of the linked list
void insertAtFront() {
    int data;
    Node* temp = new Node;

    cout << "Enter number to be inserted: ";
    cin >> data;
    temp->info = data;

    temp->link = start;
    start = temp;
}

// Function to insert at the end of the linked list
void insertAtEnd() {
    int data;
    Node* temp = new Node;
    Node* head;

    cout << "Enter number to be inserted: ";
    cin >> data;

    temp->link = nullptr;
    temp->info = data;
    head = start;

    while (head->link != nullptr) {
        head = head->link;
    }

    head->link = temp;
}

// Function to insert at any specified position in the linked list
void insertAtPosition() {
    Node* temp, * newnode;
    int pos, data, i = 1;
    newnode = new Node;

    cout << "Enter position and data: ";
    cin >> pos >> data;

    temp = start;
    newnode->info = data;
    newnode->link = nullptr;

    while (i < pos - 1) {
        temp = temp->link;
        i++;
    }

    newnode->link = temp->link;
    temp->link = newnode;
}

// Function to delete from the front of the linked list
void deleteFirst() {
    Node* temp;
    if (start == nullptr)
        cout << "List is empty\n";
    else {
        temp = start;
        start = start->link;
        delete temp;
    }
}

// Function to delete from the end of the linked list
void deleteEnd() {
    Node* temp, * prevnode;
    if (start == nullptr)
        cout << "List is Empty\n";
    else {
        temp = start;
        while (temp->link != nullptr) {
            prevnode = temp;
            temp = temp->link;
        }
        delete temp;
        prevnode->link = nullptr;
    }
}

// Function to delete from any specified position from the linked list
void deletePosition() {
    Node* temp, * position;
    int i = 1, pos;

    // If LL is empty
    if (start == nullptr)
        cout << "List is empty\n";
    else {
        cout << "Enter index : ";

        // Position to be deleted
        cin >> pos;
        position = new Node;
        temp = start;

        // Traverse till position
        while (i < pos - 1) {
            temp = temp->link;
            i++;
        }

        // Change Links
        position = temp->link;
        temp->link = position->link;

        // Free memory
        delete position;
    }
}

// Driver Code
int main() {
    int choice;
    while (true) {
        cout << "\n\t1 To see list\n";
        cout << "\t2 For insertion at starting\n";
        cout << "\t3 For insertion at end\n";
        cout << "\t4 For insertion at any position\n";
        cout << "\t5 For deletion of first element\n";
        cout << "\t6 For deletion of last element\n";
        cout << "\t7 For deletion of element at any position\n";
        cout << "\t8 To exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            traverse();
            break;
        case 2:
            insertAtFront();
            break;
        case 3:
            insertAtEnd();
            break;
        case 4:
            insertAtPosition();
            break;
        case 5:
            deleteFirst();
            break;
        case 6:
            deleteEnd();
            break;
        case 7:
            deletePosition();
            break;
        case 8:
            exit(1);
        default:
            cout << "Incorrect Choice\n";
            exit(0);
        }
    }
    return 0;
}

