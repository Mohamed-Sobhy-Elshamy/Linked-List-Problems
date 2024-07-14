#include <bits/stdc++.h>
using namespace std;
/*
Easy *
Two Linked Lists are identical when they have the same data and the arrangement of data
is also the same. Write a function to check if the given two linked lists are identical.

Examples:
Input: a = 1->2->3->4, b = 1->2->3->4
Output: Identical
Input: a = 1->3->5->2, b = 1->3->4->6
Output: Not Identical
*/
struct Node {
    int data;
    Node* next;
};
// check function
bool areIdentical(Node* firstList, Node* secondList) {
    while(firstList != NULL && secondList != NULL) {
        if(firstList->data != secondList->data)
            return false;

        // if we here -> first and second are not NULL and data is same
        // move to next nodes in both lists
        firstList = firstList->next;
        secondList = secondList->next;
    }
    return (firstList == NULL && secondList == NULL);
}
// push function -> Nodes
void Push(Node* head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = head;
    head = newNode;
}

int main()
{
    // Using linear traversal
    Node* first = NULL;
    Node* second = NULL;
    Push(first, 1);
    Push(first, 2);
    Push(first, 3);
    Push(second, 1);
    Push(second, 2);
    Push(second, 3);

    if(areIdentical(first, second)) {
        cout << "Identical" << endl;
    } else {
        cout << "Not Identical" << endl;
    }

    return 0;
}
