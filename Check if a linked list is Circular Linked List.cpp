#include <bits/stdc++.h>
using namespace std;
/*
Easy *
##MICROSOFT##
Given a singly linked list, find if the linked list is circular or not.

A linked list is called circular if it is not NULL-terminated
and all nodes are connected in the form of a cycle.
Below is an example of a circular linked list.
*/
struct Node {
    int data;
    Node* next;
};

void pushNode(Node*& head_ref, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = head_ref;
    head_ref = newNode;
}
// this function return true if given linked list
bool isCircular(Node* head) {
    // an empty list is circular
    if(head == NULL)
        return true;
    // next of head
    Node* nextNode = head->next;

    // this loop would stop in both cases 1 if circular
    // 2 not circular
    while(nextNode != NULL && nextNode != head)
        nextNode = nextNode->next;

    // if loop stopped because of circular condition
    return nextNode == head;
}

int main()
{
    Node* head = NULL;

    pushNode(head, 1);
    pushNode(head, 2);
    pushNode(head, 3);
    pushNode(head, 4);

    isCircular(head) ? cout << "YES\n" : cout << "NO\n";
    // output : NO

    // make a linked list circular
    head->next->next->next->next = head;

    isCircular(head)? cout << "YES\n" : cout << "NO\n";
    // output : YES

    // Time complexity : O(n)
    // Space complexity : O(1)

    return 0;
}
/*
The idea is to store head of the linked list and traverse it.
If iterator reaches NULL, linked list is not circular. else If it reaches head again,
then linked list is circular.

Follow the given steps to solve the problem:

Declare a Node pointer node and initialize it to the head’s next
Move node pointer to the next node, while the node is not equal to nullptr and node is not equal to the head
After coming out of the loop, check if the node is equal to head then return true, else return false
*/
