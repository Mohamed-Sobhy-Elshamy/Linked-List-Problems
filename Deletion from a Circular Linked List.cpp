#include <bits/stdc++.h>
using namespace std;
/*
Medium *
We have already discussed circular linked list and traversal in a circular linked list in the below articles:
In this article, we will learn about deleting a node from a circular linked list.
Consider the linked list as shown below:

We will be given a node and our task is to delete that node from the circular linked list.

Examples:
Input : 2->5->7->8->10->(head node)
        data = 5
Output : 2->7->8->10->(head node)

Input : 2->5->7->8->10->(head node)
         7
Output : 2->5->8->10->(head node)
*/
struct Node {
    int data;
    Node* next;
};
// push nodes at the beginning of a circular list
void pushNode(Node*& head_ref, int newData) {
    // create a new node and make head as next of it
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = head_ref;

    // list is not null
    if(head_ref != NULL) {
        // find the node before head and update next of it
        Node* temp = head_ref;
        while(temp->next != head_ref) {
            temp = temp->next;
        }
        temp->next = newNode;
    } else {
        newNode->next = newNode; // for the first node
    }
    head_ref = newNode;
}

// Function to delete a given node from the list
void deleteNode(Node*& head, int key) {
    // if list is empty
    if(head == NULL)
        return;

    // if the list contains a single node
    if(head->data == key && head->next == head) {
        delete(head);
        head = NULL;
        return;
    }
    Node* last = head, *del;
    // if head is to be delete
    if(head->data == key) {
        // find the last node of the list
        while(last->next != head)
            last = last->next;

        // point last node to the next of head
        // the second node of the list
        last->next = head->next;
        delete(head);
        head = last->next;
    }
    // either the node to be deleted is not found or the end of list
    while(last->next != head && last->next->data != key) {
        last = last->next;
    }
    // if node to be deleted was found
    if(last->next->data == key) {
        del = last->next;
        last->next = del->next;
        delete(del);
    } else {
        cout << "Not match key found" << endl;
    }
}


// print list
void print_list(Node* head) {
    Node* ptr = head;
    if(head != NULL) {
        do {
            cout << ptr->data << " ";
            ptr = ptr->next;
        } while(ptr != head);
    }
    cout << endl;
}

int main()
{
    // initialize lists as empty
    Node* head = NULL;

    // create list will be 2->5->7->8->10
    pushNode(head, 2);
    pushNode(head, 5);
    pushNode(head, 7);
    pushNode(head, 8);
    pushNode(head, 10);

    cout << "List before deletion: ";
    print_list(head);

    deleteNode(head, 7);

    cout << "List after deletion: ";
    print_list(head);

    return 0;
}
/*
Algorithm
Case 1: List is empty.
If the list is empty we will simply return.

Case 2:List is not empty

If the list is not empty then we define two pointers curr and prev and initialize the pointer curr with the head node.
Traverse the list using curr to find the node to be deleted and before moving to curr to the next node, every time set prev = curr.
If the node is found, check if it is the only node in the list. If yes, set head = NULL and free(curr).
If the list has more than one node, check if it is the first node of the list. Condition to check this( curr == head). If yes, then move prev until it reaches the last node. After prev reaches the last node, set head = head -> next and prev -> next = head. Delete curr.
If curr is not the first node, we check if it is the last node in the list. Condition to check this is (curr -> next == head).
If curr is the last node. Set prev -> next = head and delete the node curr by free(curr).
If the node to be deleted is neither the first node nor the last node, then set prev -> next = curr -> next and delete curr.
*/
