#include <bits/stdc++.h>
using namespace std;
/*
Split a Circular Linked List into two halves
head -> 1 -> 2 -> 3 -> 4
        ^              |
        |              |
        ---------------v
Original linked list

head-2 -> 3 -> 4
          ^    |
          |    |
          -----v
Result linked list 1

head-1 -> 1 -> 2
          ^    |
          |    |
          -----v
Result linked list 2
If there are odd number of nodes, then first list should contain one extra.
*/
struct Node {
    int data;
    Node* next;
};
// push nodes at beginning of a circular list
void Push(Node*& head_ref, int newData) {
    Node* ptr1 = new Node();
    ptr1->data = newData;

    if (head_ref == NULL) {
        ptr1->next = ptr1;
    } else {
        Node* temp = head_ref;
        while (temp->next != head_ref) {
            temp = temp->next;
        }
        temp->next = ptr1;
        ptr1->next = head_ref;
    }
    head_ref = ptr1;
}
// Function to split a list into lists - head1_ref and head2_ref are
// reference to head nodes of the two result
void splitList(Node* head, Node*& head1_ref, Node*& head2_ref) {
    if(head == NULL)
        return;

    Node* slow_ptr = head;
    Node* fast_ptr = head;


    // if are odd nodes in circular then fast->next becomes head and for even nodes
    // fast->next->next becomes head
    while(fast_ptr->next != head && fast_ptr->next->next != head) {
        fast_ptr = fast_ptr->next->next;
        slow_ptr = slow_ptr->next;
    }
    // if are even elements in list then move fast_ptr
    if(fast_ptr->next->next == head)
        fast_ptr = fast_ptr->next;

    // set the head pointer of first half
    head1_ref = head;

    // set the head pointer of second half
    if(head->next != head)
        head2_ref = slow_ptr->next;

    // make second half circular
    fast_ptr->next = slow_ptr->next;

    // make first half circular
    slow_ptr->next = head;
}
// function to print nodes
void printList(Node* head) {
    Node* temp = head;
    if (head != NULL) {
        cout << endl;
        while (temp->next != head) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << temp->data << " ";
    }
}

int main()
{
    // Initialize lists as empty
    Node *head = NULL;
    Node *head1 = NULL;
    Node *head2 = NULL;

    // Create list will be 12->56->2->11
    Push(head, 12);
    Push(head, 56);
    Push(head, 2);
    Push(head, 11);

    cout << "Original circular linked list: ";
    printList(head);

    // split the list
    splitList(head, head1, head2);

    cout << endl;
    cout << "First circular linked list: ";
    printList(head1);

    cout << endl;
    cout << "Second circular linked list: ";
    printList(head2);

    return 0;
}
/*
The algorithm.
1) Store the mid and last pointers of the circular linked list using tortoise and hare algorithm.
2) Make the second half circular.
3) Make the first half circular.
4) Set head (or start) pointers of the two linked lists.
In the below implementation, if there are odd nodes in the given circular linked list then the first result list has 1 more node than the second result list.
*/
