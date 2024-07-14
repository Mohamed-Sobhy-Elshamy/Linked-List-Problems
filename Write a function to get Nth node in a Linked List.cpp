#include <bits/stdc++.h>
using namespace std;
/*
Easy *
Write a GetNth() function that takes a linked list and an integer index and
returns the data value stored in the node at that index position.

Example:
Input:  1->10->30->14,  index = 2
Output: 30
The node at index 2 is 30
*/
struct Node {
    int data;
    Node* next;
};
// Function -> Push nodes
void pushNodes(Node*& head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = head;
    head = newNode;
}
// Function -> Get index
int getNth(Node* head, int index) {
    Node* current = head;
    int counter = 0;
    while(current != NULL) {
        if(counter == index) {
            return (current->data);
        }

        counter++;
        current = current->next;
    }
    return 0;

}

int main()
{
    // Start with the empty list
    Node* Head = NULL;

    pushNodes(Head, 1);
    pushNodes(Head, 4);
    pushNodes(Head, 1);
    pushNodes(Head, 12);
    pushNodes(Head, 1);

    // function
    cout << "Element at index 3 is " << getNth(Head, 3) << endl;

    // Time Complexity: O(n)
    // Space Complexity: O(1) -> space created for variables


    return 0;
}
