#include <bits/stdc++.h>
using namespace std;
/*
Easy *
Given a Linked List and a number N, write a function that returns the value
at the Nth node from the end of the Linked List.

Examples:
Input: 1 -> 2 -> 3 -> 4, N = 3
Output: 2
Input: 35 -> 15 -> 4 -> 20, N = 4
Output: 35
*/
struct Node {
public:
    int data;
    Node* next;
};

void printNthFromLast(Node* head, int num) {
    int len = 0, i;
    Node* temp = head;

    // length nodes of linked list
    while(temp != NULL) {
        temp = temp->next;
        len++;
    }
    // check
    if(num > len)
        return;

    temp = head;

    for(i=1; i<len-num+1; i++) {
        temp = temp->next;
    }
    cout << temp->data << endl;

    return;
}

void Push(Node*& headRef, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = headRef;
    headRef = newNode;
}

int main()
{
    Node* head = NULL;
    // Create linked list
    Push(head, 20);
    Push(head, 4);
    Push(head, 15);
    Push(head, 35);

    // Function call
    printNthFromLast(head, 4);

    // Time Complexity: O(N) -> N is size of linked list
    // Space Complexity: O(1)

    // Output: 35

    return 0;
}
