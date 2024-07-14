#include <bits/stdc++.h>
using namespace std;
/*
Intermediate *
##MICROSOFT PROBLEM##
Given a sorted linked list, delete all nodes that have duplicate numbers (all occurrences),
leaving only numbers that appear once in the original list.

Examples:
Input : 23->28->28->35->49->49->53->53
Output : 23->35
Input : 11->11->11->11->75->75
Output : empty List
*/
struct Node {
    int data;
    Node* next;
};

void Push(Node*& head, int newData) {
    Node* newNode = new Node;
    newNode->data = newData;
    newNode->next = head;
    head = newNode;
}

void removeAllDuplicates(Node*& start) {
    // Create a fake node -> pointing to original head
    Node* fake_node = new Node;
    // point to original head
    fake_node->next = start;
    // pointing to last node which has no duplicate
    Node* prev = fake_node;
    // to traverse the linked
    Node* current = start;

    while(current != NULL) {
        // until the current, previous values are same
        while(current->next != NULL && prev->next->data == current->next->data) {
            current = current->next;
        }

        // current has unique value -> current is not updated
        // move prev pointer to next node
        if(prev->next == current)
            prev = prev->next;

        // current is updated to the last duplicate
        // make prev the next of current
        else
            prev->next = current->next;

        current = current->next;
    }
    // update original head to the next of fake node
    start = fake_node->next;
}

void printList(Node* ptr) {
    while(ptr != NULL) {
        cout << ptr->data << " " ;
        ptr = ptr->next;
    }
}

int main()
{
    // create node
    Node* head = NULL;
    // push nodes
    Push(head, 23);
    Push(head, 28);
    Push(head, 28);
    Push(head, 35);
    Push(head, 46);
    Push(head, 46);
    Push(head, 50);
    Push(head, 50);

    cout << "List before removal of duplicates : " << endl;
    printList(head);

    removeAllDuplicates(head);

    cout << endl;
    cout << "List after removal of duplicates : " << endl;
    printList(head);

    // Time Complexity : O(N)
    // Space Complexity: O(1)

    return 0;
}
/*
The idea is to maintain a pointer (prev) to the node which just previous to the block of nodes
we are checking for duplicates. In the first example,
the pointer prev would point to 23 while we check for duplicates for node 28.
Once we reach the last duplicate node with value 28 (name it current pointer),
we can make the next field of prev node to be the next of current and update current=current.next.
This would delete the block of nodes with value 28 which has duplicates.
*/
