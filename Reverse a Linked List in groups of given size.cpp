#include <bits/stdc++.h>
using namespace std;
/*
Hard *
##MICROSOFT & AMAZON##
Given a linked list, write a function to reverse every k nodes (where k is an input to the function).

Example:
Input: 1->2->3->4->5->6->7->8->NULL, K = 3
Output: 3->2->1->6->5->4->8->7->NULL
Input: 1->2->3->4->5->6->7->8->NULL, K = 5
Output: 5->4->3->2->1->8->7->6->NULL
*/
struct Node {
    int data;
    Node* next;
};

void pushNodes(Node*& head_ref, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = head_ref;
    head_ref = newNode;
}

// reverse the linked list in groups of size k
Node* reverseList(Node* head, int k) {
    if(!head) // base case
        return NULL;

    Node* current = head;
    Node* Next = NULL;
    Node* prev = NULL;
    int counter = 0;

    // reverse first k nodes
    while(current != NULL && counter < k) {
        Next = current->next;
        current->next = prev;
        prev = current;
        current = Next;
        counter++;
    }
    // Next is now a pointer to (k+1)th node recursively call for the list starting from current
    if(Next != NULL)
        head->next = reverseList(Next, k);
    // prev is new head
    return prev;
}

void printList(Node* ptr) {
    while(ptr != NULL) {
        cout << ptr->data << " " ;
        ptr = ptr->next;
    }
}

int main()
{
    Node* head = NULL;

    // create linked list
    pushNodes(head, 9);
    pushNodes(head, 8);
    pushNodes(head, 7);
    pushNodes(head, 6);
    pushNodes(head, 5);
    pushNodes(head, 4);
    pushNodes(head, 3);
    pushNodes(head, 2);
    pushNodes(head, 1);

    cout << "Given linked list" << endl;
    printList(head);

    head = reverseList(head, 3);
    cout << endl;
    cout << "Reversed linked list" << endl;
    printList(head);


    // Reversed linked list
    // 3 2 1 6 5 4 9 8 7
    // Time complexity: O(n)
    // Space complexity: O(n/k)
    // For each Linked List of size n, n/k or (n/k)+1 calls will be made during the recursion.


    return 0;
}
/*
Reverse the first sub-list of size k. While reversing keep track of the next node and previous node. Let the pointer to the next node be next and pointer to the previous node be prev. See this post for reversing a linked list.
head->next = reverse(next, k) ( Recursively call for rest of the list and link the two sub-lists )
Return prev ( prev becomes the new head of the list (see the diagrams of an iterative method of )
*/
