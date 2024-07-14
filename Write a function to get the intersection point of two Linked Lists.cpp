#include <bits/stdc++.h>
using namespace std;
/*
Intermediate *
##MICROSOFT & AMAZON##
There are two singly linked lists in a system. By some programming error,
the end node of one of the linked lists got linked to the second list,
forming an inverted Y-shaped list. Write a program to get the point where two linked lists merge.
*/
struct Node {
public:
    int data;
    Node* next;
};

void pushNodes(Node*& headRef, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = headRef;
    headRef = newNode;
}
// Using two nested loops
// outer loop -> 1st
// inner loop -> 2nd
// Function to get the intersection node
Node* getIntersectionNode(Node* head1, Node* head2) {
    while (head2) {
        Node* temp = head1;
        while (temp) {
            // if both nodes are same
            if (temp == head2)
                return head2;
            temp = temp->next;
        }
        head2 = head2->next;
    }
    // if not present between the lists
    return NULL;
}

int main()
{
    /*
        Create two linked lists

        1st 3->6->9->15->30
        2nd 10->15->30

        15 is the intersection point
    */
    Node* newNode;

    // Addition of new nodes
    Node* head1 = new Node();
    head1->data = 10;

    Node* head2 = new Node();
    head2->data = 3;

    newNode = new Node();
    newNode->data = 6;
    head2->next = newNode;

    newNode = new Node();
    newNode->data = 9;
    head2->next->next = newNode;

    newNode = new Node();
    newNode->data = 15;
    head1->next = newNode;
    head2->next->next->next = newNode;

    newNode = new Node();
    newNode->data = 30;
    head1->next->next = newNode;

    head1->next->next->next = NULL;

    Node* intersectionPoint = getIntersectionNode(head1, head2);

    if (!intersectionPoint)
        cout << " No Intersection Point \n";
    else
        cout << "Intersection Point: "
             << intersectionPoint->data << endl;


    // Output : 15
    // Time Complexity: O(m*n), where m and n are number of nodes in two linked list.
    // Auxiliary Space: O(1)


    return 0;
}
/*
Use 2 nested for loops. The outer loop will be for each node
of the 1st list and the inner loop will be for the 2nd list.
In the inner loop, check if any of the nodes of the 2nd list
is the same as the current node of the first linked list.
The time complexity of this method will be O(M * N)
where m and n are the numbers of nodes in two lists.
*/
