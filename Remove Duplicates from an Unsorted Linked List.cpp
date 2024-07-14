#include <bits/stdc++.h>
using namespace std;
/*
Intermediate *
Given an unsorted Linked List, the task is to remove duplicates from the list.
##AMAZON PROBLEM##

Examples:
Input: 12 -> 11 -> 12 -> 21 -> 41 -> 43 -> 21
Output: 12 -> 11 -> 21 -> 41 -> 43
Explanation: Second occurrence of 12 and 21 are removed.
Input: 12 -> 11 -> 12 -> 21 -> 41 -> 43 -> 21
Output: 12 -> 11 -> 21 -> 41 -> 43
-------------
The most simple approach to solve this,
is to check each node for duplicate in the Linked List one by one.
*/
struct Node {
    int data;
    Node* next;
};

void Push(Node*& head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = head;
    head = newNode;
}

void removeDuplicates(Node* start) {
    Node* ptr1, *ptr2, *dup;
    ptr1 = start;

    // pick elements one by one
    while(ptr1 != NULL && ptr1->next != NULL) {
        ptr2 = ptr1;
        // Compare the picked element with rest all elements
        while(ptr2->next != NULL) {
            // if duplicate then delete it
            if(ptr1->data == ptr2->next->data) {
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                delete(dup);
            } else {
                ptr2 = ptr2->next;
            }

        }
        ptr1 = ptr1->next;
    }
}

void printList(Node* ptr) {
    while(ptr != NULL) {
        cout << " " << ptr->data;
        ptr = ptr->next;
    }
}

int main()
{
    Node* start = NULL;

    Push(start, 10);
    Push(start, 12);
    Push(start, 11);
    Push(start, 11);
    Push(start, 12);
    Push(start, 11);
    Push(start, 10);

    cout << "Linked list before removing duplicates: " ;
    printList(start);

    removeDuplicates(start);

    cout << endl;
    cout << "Linked list after removing duplicates: " ;
    printList(start);

    // Time Complexity: O(N^2)
    // Auxiliary Space: O(1)

    return 0;
}
