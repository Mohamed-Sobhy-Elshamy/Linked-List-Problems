#include <bits/stdc++.h>
using namespace std;
/*
Intermediate*
##AMAZON & MICROSOFT PROBLEM##
Given a singly linked list of characters, write a function that
returns true if the given list is a palindrome, else false.
Examples:

Input: R->A->D->A->R->NULL
Output: Yes
Input: C->O->D->E->NULL
Output: No
*/
struct Node {
    int data;
    Node* next;
};
// Push function
void Push(Node* head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = head;
    head = newNode;
}
// Reverse -> this function may change the head
void Reverse(Node*& head_ref) {
    Node* prev = NULL;
    Node* current = head_ref;
    Node* next;

    while(current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head_ref = prev;
}
// check if two input lists have same data
bool compareLists(Node* head1, Node* head2) {
    Node* temp1 = head1;
    Node* temp2 = head2;

    while(temp1 && temp2) {
        if(temp1->data == temp2->data) {
            temp1 = temp1->next;
            temp2 = temp2->next;
        } else {
            return 0;
        }
    }
    if(temp1 == NULL && temp2 == NULL)
        return 1;
    return 0;
}
// check if given linked list is palindrome or not
bool isPalindrome(Node* head) {
    Node* slow_ptr = head, *fast_ptr = head;
    Node* second_half, *prev_of_slow_ptr = head;
    // Handle odd size list
    Node* midNode = NULL;
    // Initialize result
    bool res = true;

    if(head != NULL && head->next != NULL) {
        // get the middle - move slow by 1 and fast by 2
        // slow will have the middle node
        while(fast_ptr != NULL && fast_ptr != NULL) {
            fast_ptr = fast_ptr->next->next;
            // we need prev of slow for lists with odd element
            prev_of_slow_ptr = slow_ptr;
            slow_ptr = slow_ptr->next;
        }
        // fast become null when are even, and not null for odd
        // we skip middle node for odd and store it
        // so that we can restore the original list
        if(fast_ptr != NULL) {
            midNode = slow_ptr;
            slow_ptr = slow_ptr->next;
        }
        // now reverse the second half and compare it with first half
        second_half = slow_ptr;
        // null terminate first half
        prev_of_slow_ptr->next = NULL;
        // reverse the second
        Reverse(second_half);
        // compare
        res = compareLists(head, second_half);
        // original linked list
        Reverse(second_half);

        if(midNode != NULL) {
            prev_of_slow_ptr->next = midNode;
            midNode->next = second_half;
        } else {
            prev_of_slow_ptr->next = second_half;
        }
    }
    return res;
}

// print linked list
void printList(Node* ptr) {
    while(ptr != NULL) {
        cout << ptr->data << "->";
        ptr = ptr->next;
    }
    cout << "NULL" << endl;
}


// by Reversing the Linked List
int main()
{
    // empty linked list
    Node* head = NULL;
    char str[] = "abacaba";
    int i;

    for(i=0; str[i] != '\0'; i++) {
        Push(head, str[i]);
    }
    isPalindrome(head) ? cout << "Is Palindrome" << "\n"
        : cout << "Not Palindrome" << endl;

    // Time Complexity: O(N)
    // Auxiliary Space: O(1)

    return 0;
}
/*
Follow the steps below to solve the problem:

Get the middle of the linked list.
Reverse the second half of the linked list.
Check if the first half and second half are identical.
Construct the original linked list by reversing the second half again and attaching it back to the first half
*/
