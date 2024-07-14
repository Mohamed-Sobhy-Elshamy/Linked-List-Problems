#include <bits/stdc++.h>
using namespace std;
/*
Given a singly linked list, we have to convert it into circular linked list.
For example, we have been given a singly linked list with four nodes and
we want to convert this singly linked list into circular linked list.

Approach: The idea is to traverse the singly linked list and check if the node is the last node or not.
If the node is the last node i.e pointing to NULL then make it point to the starting node i.e head node. Below is the implementation of this approach.
*/
struct Node {
    int data;
    Node* next;
};

void pushNodes(Node*& head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = head;
    head = newNode;
}
// function -> convert singly int circular
Node* convertToCircular(Node* head) {
    // declare node start assign head
    Node* start = head;
    // check head->next not = null
    while(head->next != NULL)
        head = head->next;
    // head->next points to null
    // start assign to head->next node
    head->next = start;
    return start;
}

void displayList(Node* node) {
    Node* start = node;

    while(node->next != start) {
        cout << node->data << " -> ";
        node = node->next;
    }
    // print the last node of circular
    cout << " " << node->data;
}

int main()
{
    // empty linked list
    Node* head_ref = NULL;

    // singly linked list
    // 17->22->13->14->15
    pushNodes(head_ref, 15);
    pushNodes(head_ref, 14);
    pushNodes(head_ref, 13);
    pushNodes(head_ref, 22);
    pushNodes(head_ref, 17);

    // call function convert
    convertToCircular(head_ref);
    cout << "Display linked list : " ;
    displayList(head_ref);

    // output: 17 22 13 14 15
    // Time Complexity: O(n)
    // Space Complexity: O(1)

    return 0;
}
/*
Here are the algorithmic steps to convert a singly linked list into a circular linked list:

Step 1 : Initialize a pointer current to the head node of the singly linked list.
Step 2 : Traverse the linked list by moving the current pointer to the next node until it
         reaches the last node (i.e., the node whose next pointer is NULL).
Step 3 : Set the next pointer of the last node to point back to the head node
        of the linked list.
The singly linked list is now a circular linked list.

Note that step 3 is what actually converts the singly linked list into a
circular linked list.
*/
