#include <bits/stdc++.h>
using namespace std;
/*
Intermediate *
Given a singly linked list with two value x and y,
the task is to swap two nodes having values x and y without swapping data.

Examples:
Input: 10->15->12->13->20->14,  x = 12, y = 20
Output: 10->15->20->13->12->14
Input: 10->15->12->13->20->14,  x = 10, y = 20
Output: 20->15->12->13->10->14
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

void swapNodes(Node*& head_ref, int x, int y) {
    // x and y are same
    if(x == y)
        return;

    // search for x -> keep track of prevX and currX
    Node* prevX = NULL, *currX = head_ref;
    while(currX && currX->data != x) {
        prevX = currX;
        currX = currX->next;
    }

    // Search for y -> Keep track
    Node* prevY = NULL, *currY = head_ref;
    while(currY && currY->data != y) {
        prevY = currY;
        currY = currY->next;
    }

    // x or y is not present
    if(currX == NULL || currY == NULL)
        return;

    // x is not head
    if(prevX != NULL)
        prevX->next = currY;
    else // y as a head
        head_ref = currY;

    // y is not head
    if(prevY != NULL)
        prevY->next = currX;
    else // x as a head
        head_ref = currX;

    // swap next pointers
    Node* temp = currY->next;
    currY->next = currX->next;
    currX->next = temp;
}

void printList(Node* ptr) {
    while(ptr != NULL) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

int main()
{
    // create node
    Node* start = NULL;
    // create linked list
    // 1->2->3->4->5->6->7
    Push(start, 7);
    Push(start, 6);
    Push(start, 5);
    Push(start, 4);
    Push(start, 3);
    Push(start, 2);
    Push(start, 1);

    cout << "Linked list before calling swap nodes : ";
    printList(start);

    swapNodes(start, 4, 3);

    cout << endl;
    cout << "Linked list after calling swap nodes : ";
    printList(start);

    // Time Complexity: O(N)
    // Space Complexity: O(1)


    return 0;
}
/*
When swapping 2 nodes, x and y, in a linked list, there are a few cases that can arise:
x and y are adjacent to each other, and
One of x or y is the head node of the list.
None of x or y is either a head node or a tail node.
x and y are not adjacent to each other, and:
One of x or y is the head node of the list.
None of x or y is either a head node or a tail node.
x or y don’t even exist in the linked list.
Therefore, our solution must handle all these cases.

Naive Approach:

The idea is to first search x and y in the given linked list.
If any of them is not present, then return. While searching for x and y,
keep track of current and previous pointers. First change next of previous pointers,
then change next of current pointers.
*/
