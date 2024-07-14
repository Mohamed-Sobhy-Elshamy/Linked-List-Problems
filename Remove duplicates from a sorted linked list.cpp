#include <bits/stdc++.h>
using namespace std;
/*
Medium
##MICROSOFT && ORACLE##
Write a function that takes a list sorted in non-decreasing order and deletes any duplicate nodes from the list.
The list should only be traversed once.
For example if the linked list is 11->11->11->21->43->43->60 then removeDuplicates()
should convert the list to 11->21->43->60.
*/
struct Node {
    int data;
    Node* next;
};
// push from begin
void pushNode(Node*& head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = head;
    head = newNode;
}
// function -> remove duplicates from a sorted list
void removeDuplicatesNodes(Node* head) {
    // pointer to traverse the list
    Node* current = head;
    // pointer to store the next pointer of a node to be deleted
    Node* next_next;

    // check list is empty
    if(current == NULL)
        return;
    // traverse the list till last node
    while(current->next != NULL) {
        // compare current node with next node
        if(current->data == current->next->data) {
            // this step is important
            // store next next of the current in next next
            next_next = current->next->next;
            // delete
            free(current->next);
            current->next = next_next;
        } else {
            current = current->next;
        }
    }
}



void print_list(Node* ptr) {
    while(ptr != NULL) {
        cout << " " << ptr->data ;
        ptr = ptr->next;
    }
}

int main()
{
    // empty linked list
    Node* head = NULL;
    // create a sorted list
    // 11->11->11->13->13->20
    pushNode(head, 20);
    pushNode(head, 13);
    pushNode(head, 13);
    pushNode(head, 11);
    pushNode(head, 11);
    pushNode(head, 11);

    cout << "Linked list before duplicate removal " << endl;
    print_list(head);

    // call function
    removeDuplicatesNodes(head);

    cout << endl;
    cout << "Linked list after duplicate removal " << endl;

    print_list(head);

    // output: 11 13 20
    // Time Complexity: O(n)
    // Space Complexity: O(1)

    return 0;
}
/*
Algorithm: Traverse the list from the head (or start) node.
While traversing, compare each node with its next node.
If the data of the next node is the same as the current node then delete the next node.
Before we delete a node, we need to store the next pointer of the node
*/
