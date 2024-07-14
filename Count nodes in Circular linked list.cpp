#include <bits/stdc++.h>
using namespace std;
/*
Given a circular linked list, count the number of nodes in it. For example,
the output is 5 for the below list.

Approach: We use the concept used in Circular Linked List | Set 2 (Traversal).
While traversing, we keep track of the count of nodes.
*/
struct Node {
    int data;
    Node* next;
};

Node* pushNode(Node*& headRef, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;

    if(headRef == NULL) {
        newNode->next = newNode;
        return newNode;
    }
    Node* last = headRef;
    while(last->next != headRef)
        last = last->next;

    newNode->next = headRef;
    last->next = newNode;
    return newNode;
}

int countNode(Node* head) {
    Node* temp = head;
    int result = 0;
    if (head != NULL) {
        do {
            temp = temp->next;
            result++;
        } while (temp != head);
    }
    return result;
}

int main()
{
    Node* head = NULL;

    head = pushNode(head, 12);
    head = pushNode(head, 56);
    head = pushNode(head, 2);

    cout << countNode(head) << endl;

    // output: 3

    // Time complexity: O(n)
    // Space complexity: O(1)

    return 0;
}
