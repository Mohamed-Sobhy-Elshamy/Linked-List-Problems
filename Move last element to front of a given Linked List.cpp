#include <bits/stdc++.h>
using namespace std;
/*
Easy *
Write a function that moves the last node to the front in a given Singly Linked List.

Examples:
Input: 1->2->3->4->5
Output: 5->1->2->3->4
Input: 3->8->1->5->7->12
Output: 12->3->8->1->5->7
*/
struct Node {
public:
    int data;
    Node* next;
};

void moveToFront(Node*& head) {
    // check
    if(head == NULL || head->next == NULL)
        return;
    // initialize second last and last pointers
    Node* secLast = NULL;
    Node* last = head;

    while(last->next != NULL) {
        secLast = last;
        last = last->next;
    }

    secLast->next = NULL;
    last->next = head;
    // change the head pointer to point to last node
    head = last;
}

void Push(Node*& headRef, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = headRef;
    headRef = newNode;
}

void printList(Node* node) {
    while(node != NULL) {
        cout << node->data << " " ;
        node = node->next;
    }
}

int main()
{
    Node* start = NULL;

    Push(start, 5);
    Push(start, 4);
    Push(start, 3);
    Push(start, 2);
    Push(start, 1);

    cout << "Linked list before moving last to front" << endl;
    printList(start);
    // Function call
    moveToFront(start);

    cout << endl;
    cout << "Linked list after removing last to front" << endl;
    printList(start);

    // Time Complexity: O(N) -> we need to traverse the list once
    // Space Complexity: O(1) -> Constant extra space is used

    // Output: 5 1 2 3 4

    return 0;
}
