#include <bits/stdc++.h>
using namespace std;
/*
Insert value in sorted way in a sorted doubly linked list
Given a sorted doubly linked list and a value to insert, write a function to insert the value in sorted way.
Initial doubly linked list

Example:
Input : head : 3 <-> 5 <-> 8 <-> 10 <-> 12
insert      x = 9

output: head : 3 <-> 5 <-> 8 <-> 9 <-> 10 <-> 12
*/
struct Node {
    int data;
    Node* next, *prev;
};
// Function to create node and return a new node
Node* createNode(int newData) {
    // allocate node
    Node* newNode = new Node();

    // put in the data
    newNode->data = newData;
    newNode->prev = newNode->next = NULL;
    return newNode;
}
// Function to insert a new node in sorted way
void sortedInsert(Node*& head_ref, Node* newNodeToInsertion) {
    Node* current;

    // if list is empty
    if(head_ref == NULL)
        head_ref = newNodeToInsertion;

    // if the node is to be inserted at the beginning
    else if(head_ref->data >= newNodeToInsertion->data) {
        newNodeToInsertion->next = head_ref;
        newNodeToInsertion->next->prev = newNodeToInsertion;
        head_ref = newNodeToInsertion;
    } else {
        current = head_ref;

        // locate the node after which the new node is to be inserted
        while(current->next != NULL && current->next->data < newNodeToInsertion->data)
            current = current->next;

        // make the appropriate links
        newNodeToInsertion->next = current->next;

        // if the new node is not insert at the end of the list
        if(current->next != NULL)
            newNodeToInsertion->next->prev = newNodeToInsertion;

        current->next = newNodeToInsertion;
        newNodeToInsertion->prev = current;
    }
}
// Function to print the DLL
void print_list(Node* head) {
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    // Start with empty DLL
    Node* head = NULL;


    // Insert the nodes
    Node* new_node = createNode(8);
    sortedInsert(head, new_node);
    new_node = createNode(5);
    sortedInsert(head, new_node);
    new_node = createNode(3);
    sortedInsert(head, new_node);
    new_node = createNode(10);
    sortedInsert(head, new_node);
    new_node = createNode(12);
    sortedInsert(head, new_node);
    new_node = createNode(9);
    sortedInsert(head, new_node);


    cout << "Created Doubly Linked List" <<  endl;
    print_list(head);

    // Time Complexity : O(n)
    // Space Complexity : O(n)

    return 0;
}
