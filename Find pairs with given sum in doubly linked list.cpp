#include <bits/stdc++.h>
using namespace std;
/*
Given a sorted doubly linked list of positive distinct elements,
the task is to find pairs in a doubly-linked list whose sum is equal to given value x,
without using any extra space?

Example:
Input : head : 1 <-> 2 <-> 4 <-> 5 <-> 6 <-> 8 <-> 9
        x = 7
Output: (6, 1), (5,2)
*/
struct Node {
    int data;
    Node* next, *prev;
};

// Function to insert a new node at the beginning of doubly
void insertNode(Node*& head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = newNode->prev = NULL; // initialize to next and prev of null
    if(!head) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

// Function to find pair whose sum equal to given value
void pairSum(Node* head, int element_for_sum) {
    // Set two pointers, first to the beginning of DLL
    // and second to the end of DLL
    Node* first_ptr = head;
    Node* second_ptr = head;
    while(second_ptr->next != NULL)
        second_ptr = second_ptr->next;
    // To track if find a pair or not
    bool found = false;

    // The loop when 2 pointers cross each other (second->next == first)
    while(first_ptr != second_ptr && second_ptr->next != first_ptr) {
        // pair found
        if((first_ptr->data + second_ptr->data) == element_for_sum) {
            found = true;
            cout << "( " << first_ptr->data << ", "
                << second_ptr->data << " )" << endl;

            // move first in forward direction
            first_ptr = first_ptr->next;

            // move second in backward
            second_ptr = second_ptr->prev;
        } else {
            if((first_ptr->data + second_ptr->data) < element_for_sum)
                first_ptr = first_ptr->next;
            else
                second_ptr = second_ptr->prev;
        }
    }
    // if pair is not present
    if(found == false)
        cout << "No pair found";
}

int main()
{
    Node *head = NULL;
    insertNode(head, 9);
    insertNode(head, 8);
    insertNode(head, 6);
    insertNode(head, 5);
    insertNode(head, 4);
    insertNode(head, 2);
    insertNode(head, 1);

    int key = 7;

    pairSum(head, key);
    /*
        (1, 6)
        (2, 5)
    */
    // Time Complexity: O(n)
    // Space Complexity: O(1)

    return 0;
}
