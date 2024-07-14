#include <bits/stdc++.h>
using namespace std;
/*
Intermediate *
Given a linked list, check if the linked list has a loop (cycle) or not.
The below diagram shows a linked list with a loop.

The idea is to modify the node structure by adding flag in it and mark
the flag whenever visit the node.
*/
struct Node {
    int data;
    Node* next;
    int flag;
};

void Push(Node*& head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->flag = 0;
    newNode->next = head;
    head = newNode;
}

bool detectLoop(Node* Ref) {
    while(Ref != NULL) {
        // if node is already traverse
        // it means there is a cycle
        if(Ref->flag == 1)
            return true;

        // mark it is flag as 1
        Ref->flag = 1;
        Ref = Ref->next;
    }
    return false;
}

int main()
{
    // Use Modify
    Node* head = NULL;

    // Create a linked list
    Push(head, 1);
    Push(head, 2);
    Push(head, 3);
    Push(head, 4);

    // Create a cycle linked list
    head->next->next->next->next = head;

    if(detectLoop(head))
        cout << "Loop Found :)" << endl;
    else
        cout << "No Loop :(" << endl;

    // Time Complexity: O(n) -> one traversal of the loop is needed
    // Space Complexity: O(1)


    return 0;
}
