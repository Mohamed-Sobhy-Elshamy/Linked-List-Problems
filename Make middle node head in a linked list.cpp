#include <bits/stdc++.h>
using namespace std;
/*
Given a singly linked list, find middle of the linked list
and set middle node of the linked list at beginning of the linked list.

Examples:
Input  : 1 2 3 4 5
Output : 3 1 2 4 5

Input  : 1 2 3 4 5 6
Output : 4 1 2 3 5 6
*/
struct Node {
public:
    int data;
    Node* next;
};

void setMiddleHead(Node*& head) {
    if(head == NULL)
        return;
    // traverse list nodes one by one
    Node* oneNode = head;
    // traverse list nodes by skipping one
    Node* twoNode = head;

    Node* prev = NULL;
    while(twoNode != NULL && twoNode->next != NULL) {
        prev = oneNode;
        // traverse two nodes
        twoNode = twoNode->next->next;
        // traverse one node
        oneNode = oneNode->next;
    }
    // set middle node at head
    prev->next = prev->next->next;
    oneNode->next = head;
    head = oneNode;
}

void Push(Node*& headRef, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = headRef;
    headRef = newNode;
}

void printList(Node* ptr) {
    while(ptr != NULL) {
        cout << ptr->data << " " ;
        ptr = ptr->next;
    }
    cout << endl;
}


int main()
{
    // Create list of 5 Nodes
    Node* Head = NULL;
    int i;
    for(i=5; i>0; i--)
        Push(Head, i);

    cout << "list before: " ;
    printList(Head);

    setMiddleHead(Head);

    cout << "List After : ";
    printList(Head);

    // Time Complexity: O(n)
    // Space Complexity: O(1)

    return 0;
}
