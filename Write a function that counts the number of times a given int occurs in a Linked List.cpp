#include <bits/stdc++.h>
using namespace std;
/*
Easy *
Given a singly linked list and a key,
count the number of occurrences of the given key in the linked list.
For example, if the given linked list is 1->2->1->2->1->3->1 and the given key is 1,
then the output should be 4.
*/
struct Node {
    int data;
    Node* next;
};
// function push nodes in linked
void pushNodes(Node*& head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = head;
    head = newNode;
}
// function counts the number of key
int counts(Node* head, int element) {
    Node* current = head;
    int counter = 0;
    while(current != NULL) {
        if(current->data == element)
            counter++;
        current = current->next;
    }
    return counter;
}

int main()
{
    Node* head_ref = NULL;

    pushNodes(head_ref, 1);
    pushNodes(head_ref, 3);
    pushNodes(head_ref, 1);
    pushNodes(head_ref, 2);
    pushNodes(head_ref, 1);

    cout << "Count of 1 is : " << counts(head_ref, 1) << endl;

    // Output : 3
    // Time complexity: O(n)
    // Space complexity: O(1)

    return 0;
}
/*
Step 1: Start
Step 2: Create A Function Of A Linked List, Pass A Number
As Arguments And Provide The Count Of The Number To The Function.
Step 3: Initialize Count Equal To 0.
Step 4: Traverse In Linked List Until Equal Number Found.
Step 5: If Found A Number Equal To Update Count By 1.
Step 6: After Reaching The End Of The Linked List Return Count.
Step 7: Call The Function.
Step 8: Prints The Number Of Int Occurrences.
Step 9: Stop.
*/
