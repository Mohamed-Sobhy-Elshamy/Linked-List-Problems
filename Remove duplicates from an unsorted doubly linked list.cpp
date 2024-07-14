#include <bits/stdc++.h>
using namespace std;
/*
Given an unsorted doubly linked list containing n nodes.
The problem is to remove duplicate nodes from the given list.

Example:
Input : head : 8 <-> 4 <-> 4 <-> 6 <-> 4 <-> 8 <-> 4 <-> 10 <-> 12 <-> 12
output : 8 <-> 4 <-> 6 <-> 10 <-> 12
*/

// ## Using Hash table -> Implemented using unordered set
struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Function -> to delete a node in DLL
// head_ref --> pointer to head node pointer
// del --> pointer to node to deleted
void delete_node(Node*& head_ref, Node* node_is_deleted) {
    // base case
    if(head_ref == NULL || node_is_deleted == NULL)
        return;

    // if node to be deleted is head node
    if(head_ref == node_is_deleted)
        head_ref = node_is_deleted->next;

    // change next only if node to be deleted is not the last node
    if(node_is_deleted->next != NULL)
        node_is_deleted->next->prev = node_is_deleted->prev;

    // change prev only if node to be deleted is not the first node
    if(node_is_deleted->prev != NULL)
        node_is_deleted->prev->next = node_is_deleted->next;

    delete(node_is_deleted);
}

// Function -> to remove duplicates from an unsorted DLL
void removeDuplicates(Node*& head_ref) {
    // if DLL is empty
    if(head_ref == NULL)
        return;

    // unordered set US implemented as hash table
    unordered_set<int> US;
    Node* current = head_ref, *next;

    // Traverse up to the head of the list
    while(current != NULL) {
        // if current data is seen before
        if(US.find(current->data) != US.end()) {
            // store pointer to the node next to current node
            next = current->next;
            // delete the node pointed to by current
            delete_node(head_ref, current);
            // update current
            current = next;
        } else {
            // insert the current data in US
            US.insert(current->data);
            // move to the next node
            current = current->next;
        }
    }
}

// Function -> To push node at the beginning
void push_node_in_dll(Node*& head, int new_data) {
    // allocate node
    Node* new_node = new Node();
    new_node->data = new_data;
    // we are adding at the beginning prev is always null
    new_node->prev = NULL;
    // link the old list of the new node
    new_node->next = head;
    // change prev of head node to new node
    if(head != NULL)
        head->prev = new_node;
    // move the head to point to the new head
    head = new_node;
}

// To print nodes on a given DLL
void print_list(Node* head) {
    // if list is empty
    if(head == NULL)
        cout << "Doubly linked list empty" ;
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    Node* head = NULL;

    // Create the DLL
    // 8<->4<->4<->6<->4<->8<->4<->10<->12<->12
    push_node_in_dll(head, 12);
    push_node_in_dll(head, 12);
    push_node_in_dll(head, 10);
    push_node_in_dll(head, 4);
    push_node_in_dll(head, 8);
    push_node_in_dll(head, 4);
    push_node_in_dll(head, 6);
    push_node_in_dll(head, 4);
    push_node_in_dll(head, 4);
    push_node_in_dll(head, 8);

    cout << "Original Doubly linked list: " << endl;
    print_list(head);

    // call remove function
    removeDuplicates(head);

    cout << endl;
    cout << "Doubly linked list after "
        << "removing duplicates" << endl;
    print_list(head);

    // Time Complexity: O(n)
    // Space Complexity: O(n)

    return 0;
}
