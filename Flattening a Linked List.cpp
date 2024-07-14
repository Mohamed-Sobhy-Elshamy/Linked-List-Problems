#include <bits/stdc++.h>
using namespace std;
/*
Hard *
##MICROSOFT & AMAZON##
Given a Linked List of size N, where every node represents a
sub-linked-list and contains two pointers:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.
Each of the sub-linked-list is in sorted order.
Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order.
Note: The flattened list will be printed using the bottom pointer instead of next pointer.

Note: All linked lists are sorted and the resultant linked list should also be sorted
Examples:
Input:    3 -> 10 -> 7 -> 14
           |   |     |    |
           V   V     V    V
           9   47    15   22
           |         |
           V         V
           17        30

Output: 3->7->9->10->14->15->17->22->30->47
*/
struct Node {
    int data;
    Node* next, *bottom;
};
Node* head = NULL;

Node* push(Node*& head_ref, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = NULL;
    // make next of new node as head
    newNode->bottom = head_ref;
    // move the head to point to new node
    head_ref = newNode;

    return head_ref;
}

// to merge two sorted linked lists
Node* mergeList(Node* first_list, Node* second_list) {
    // if first linked list is empty then second is answer
    if(first_list == NULL)
        return second_list;

    // if second linked list is empty then first is answer
    if(second_list == NULL)
        return first_list;

    // compare the data members of two lists and put larger one in the result
    Node* result;

    if(first_list->data < second_list->data) {
        result = first_list;
        result->bottom = mergeList(first_list->bottom, second_list);
    } else {
        result = second_list;
        result->bottom = mergeList(first_list, second_list->bottom);
    }
    result->next = NULL;
    return result;
}

Node* flatten(Node* root) {
    if(root == NULL || root->next == NULL)
        return root;

    // recur for next list
    root->next = flatten(root->next);

    // now merge
    root = mergeList(root, root->next);

    // return root
    return root;
}

// print function
void printList()
{
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->bottom;
    }
    cout << endl;
}


int main()
{
    /* Let us create the following linked list
        5 -> 10 -> 19 -> 28
        |    |     |     |
        V    V     V     V
        7    20    22    35
        |          |     |
        V          V     V
        8          50    40
        |                |
        V                V
        30               45
    */

    head = push(head, 30);
    head = push(head, 8);
    head = push(head, 7);
    head = push(head, 5);

    head->next = push(head->next, 20);
    head->next = push(head->next, 10);

    head->next->next = push(head->next->next, 50);
    head->next->next = push(head->next->next, 22);
    head->next->next = push(head->next->next, 19);

    head->next->next->next
        = push(head->next->next->next, 45);
    head->next->next->next
        = push(head->next->next->next, 40);
    head->next->next->next
        = push(head->next->next->next, 35);
    head->next->next->next
        = push(head->next->next->next, 28);

    // Function call
    head = flatten(head);

    printList();

    /*
        Time Complexity: O(N * N * M) – where N is the no of nodes in the main linked list and M is the no of nodes in a single sub-linked list

        Auxiliary Space: O(1)
        Explanation: As we are merging 2 lists at a time,
    */

    return 0;
}
/*
The idea is to use the Merge() process of merge sort for linked lists. Use merge() to merge lists one by one,
recursively merge() the current list with the already flattened list. The bottom pointer is used to link nodes of the flattened list.

Follow the given steps to solve the problem:

Recursively call to merge the current linked list with the next linked list
If the current linked list is empty or there is no next linked list then return the current linked list (Base Case)
Start merging the linked lists, starting from the last linked list
After merging the current linked list with the next linked list,
return the head node of the current linked list
*/
