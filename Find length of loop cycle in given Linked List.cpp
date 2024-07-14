#include <bits/stdc++.h>
using namespace std;
/*
Intermediate*
##AMAZON PROBLEM##

Given the head of a linked list. The task is to find if a loop exists
in the linked list if yes then return the length of the loop in the linked list else return 0.

Examples:
Input: linked list =
Output: 4
Explanation: The loop is present in the below-linked list and the length of the loop is 4.

Input: linked list = 4 -> 3 -> 7 -> 9 -> 2
Output: 0
*/
struct Node {
    int data;
    Node* next;
};
// push nodes at linked list
void Push(Node*& head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = head;
    head = newNode;
}
// return count of nodes
int countNode(Node* Size) {
    int res = 1;
    Node* temp = Size;
    while(temp->next != Size) {
        res++;
        temp = temp->next;
    }
    return res;
}
// detects and counts loop nodes in the list
int countNodeInList(Node* List) {
    Node* slow_ptr = List;
    Node* fast_ptr = List;

    while(slow_ptr && fast_ptr && fast_ptr->next) {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;

        // if slow and fast meet at same point
        if(slow_ptr == fast_ptr)
            return countNode(slow_ptr);
    }
    return 0;
}
// Floyd cycle detected algorithm
int main()
{
    Node* Head = NULL;

    Push(Head, 1);
    Push(Head, 2);
    Push(Head, 3);
    Push(Head, 4);
    Push(Head, 5);
    // Create a loop linked list
    Head->next->next->next->next->next = Head->next;

    cout << countNodeInList(Head) << endl;

    // Output: 4
    /*
        Time complexity: O(N), one traversal of the linked list is needed.
        Auxiliary Space: O(1), no extra space.
    */

    return 0;
}
