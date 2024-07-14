#include <bits/stdc++.h>
using namespace std;
/*
Given Circular linked list exchange the first and the last node.
The task should be done with only one extra node, you can not declare more than one extra node,
and also you are not allowed to declare any other temporary variable.

Note: Extra node means the need of a node to traverse a list.

Input : 5 4 3 2 1
Output : 1 4 3 2 5

Input  : 6 1 2 3 4 5 6 7 8 9
Output : 9 1 2 3 4 5 6 7 8 6
*/

struct Node {
    int data;
    Node* next;
};

Node* add_to_empty(Node* head, int new_data) {
    // this function is only for empty list
    if(head != NULL)
        return head;
    // create a node dynamically
    Node* temp = new Node();
    // Assigning the data
    temp->data = new_data;
    head = temp;
    head->next = head;

    return head;
}

Node* add_begin(Node* head_ref, int newData) {
    if(head_ref == NULL)
        return add_to_empty(head_ref, newData);

    Node* ptr = new Node();
    ptr->data = newData;
    ptr->next = head_ref->next;
    head_ref->next = ptr;

    return head_ref;
}

// Function for traversing the list
void traverse(Node* head) {
    Node* ptr;
    // if list is empty
    if(head == NULL) {
        cout << "List is empty: " << endl;
        return;
    }
    // pointing to first node of list
    ptr = head;

    do {
        cout << ptr->data << " " ;
        ptr = ptr->next;
    } while(ptr != head);
}

// Function to exchange first and last nodes
Node* exchange_nodes(Node* head) {
    // if list is length 2
    if(head->next->next == head) {
        head = head->next;
        return head;
    }

    // Find pointer to previous of last node
    Node* ptr = head;
    while(ptr->next->next != head)
        ptr = ptr->next;

    // exchange first and last nodes using head and ptr
    ptr->next->next = head->next;
    head->next = ptr->next;
    ptr->next = head;
    head = head->next;

    return head;
}

int main()
{
    int i;
    Node* head = NULL;

    head = add_to_empty(head, 6);

    for(i = 5; i > 0; i--) {
        head = add_begin(head, i);
    }
    cout << "List Before: ";
    traverse(head);
    cout << endl;

    cout << "List After: ";
    head = exchange_nodes(head);
    traverse(head);

    return 0;
}
/*
Method 1: (By Changing Links of First and Last Nodes)

We first find a pointer to the previous to the last node.
Let this node be p. Now we change the next links so that the last and first nodes are swapped.
*/
