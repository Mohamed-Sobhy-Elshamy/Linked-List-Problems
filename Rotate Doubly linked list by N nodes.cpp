#include <bits/stdc++.h>
using namespace std;
/*
##AMAZON##
Given a doubly-linked list, rotate the linked list counter-clockwise by N nodes.
Here N is a given positive integer and is smaller than the count of nodes in linked list.

Examples:
Input : a  b  c  d  e   N = 2
Output : c  d  e  a  b

Input : a  b  c  d  e  f  g  h   N = 4
Output : e  f  g  h  a  b  c  d
*/
class Node {
public:
    char data;
    Node* next;
    Node* prev;
    Node(int newData) {
        this->data = newData;
        prev = NULL;
        next = NULL;
    }
};

void insertAtHead(Node*& head, int new_data) {
    Node* new_node = new Node(new_data);
    if(head == NULL) {
        head = new_node;
        return;
    }
    new_node->next = head;
    head->prev = new_node;
    head = new_node;
    return;
}

void insertAtTail(Node*& head_ref, int new_data) {
    if(head_ref == NULL) {
        insertAtHead(head_ref, new_data);
        return;
    }
    Node* temp = head_ref;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    Node* newNode = new Node(new_data);
    temp->next = newNode;
    newNode->prev = temp;
    return;
}

void display(Node* ptr) {
    while(ptr != NULL) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

void rotateByN(Node*& head, int pos) {
    // return without any changes if position = 0
    if(pos == 0)
        return;
    // finding last node
    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    // making the list is circular
    temp->next = head;
    head->prev = temp;
    // move head and temp by the given position
    int counter = 1;
    while(counter <= pos) {
        head = head->next;
        temp = temp->next;
        counter++;
    }
    // now again the list un-circular
    temp->next = NULL;
    head->prev = NULL;
}

int main()
{
    Node* ptr = NULL;
    insertAtTail(ptr, 'a');
    insertAtTail(ptr, 'b');
    insertAtTail(ptr, 'c');
    insertAtTail(ptr, 'd');
    insertAtTail(ptr, 'e');

    int N = 2;
    cout << "Given linked list" << endl;
    display(ptr);
    rotateByN(ptr, N);
    cout << endl;
    cout << endl;
    cout << "Rotate linked list" << endl;
    display(ptr);


    return 0;
}
