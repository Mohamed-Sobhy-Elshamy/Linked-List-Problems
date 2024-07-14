#include <bits/stdc++.h>
using namespace std;
/*
Medium *
##AMAZON && MICROSOFT##
Given two lists sorted in increasing order, create and return a new list representing the intersection of the two lists.
The new list should be made with its own memory — the original lists should not be changed.

Example:
Input:
First linked list: 1->2->3->4->6
Second linked list be 2->4->6->8,
Output: 2->4->6.
The elements 2, 4, 6 are common in
both the list so they appear in the
intersection list.
*/
struct Node {
    int data;
    Node* next;
};

void pushNodes(Node*& head_ref, int new_data) {
    Node* newNode = new Node();
    newNode->data = new_data;
    newNode->next = head_ref;
    head_ref = newNode;
}
// function intersect -> uses the temporary dummy
// to build up the result list
Node* sortedIntersect(Node* first_list, Node* second_list) {
    Node dummy;
    Node* tail = &dummy;
    dummy.next = NULL;

    // once one or the other list runs out -- we are done
    while(first_list != NULL && second_list != NULL) {
        if(first_list->data == second_list->data) {
            pushNodes((tail->next), first_list->data);
            tail = tail->next;
            first_list = first_list->next;
            second_list = second_list->next;
        } else if (first_list->data < second_list->data) {
            first_list = first_list->next;
        } else {
            second_list = second_list->next;
        }
    }
    return dummy.next;
}

void print_list(Node* node) {
    while(node != NULL) {
        cout << node->data << " " ;
        node = node->next;
    }
}

int main()
{
    // start with the empty lists
    Node* firstList = NULL;
    Node* secondList = NULL;
    Node* intersect = NULL;

    // Create the first sorted linked list
    // 1->2->3->4->5->6
    pushNodes(firstList, 6);
    pushNodes(firstList, 5);
    pushNodes(firstList, 4);
    pushNodes(firstList, 3);
    pushNodes(firstList, 2);
    pushNodes(firstList, 1);

    // Create the second sorted linked list
    // 2->4->6->8
    pushNodes(secondList, 8);
    pushNodes(secondList, 6);
    pushNodes(secondList, 4);
    pushNodes(secondList, 2);

    // Find the intersection two linked lists
    intersect = sortedIntersect(firstList, secondList);

    cout << "Linked list containing common items of first list & second list: " << endl;
    print_list(intersect);

    return 0;
}
/*
Using Dummy Node.
Approach:
The idea is to use a temporary dummy node at the start of the result list.
The pointer tail always points to the last node in the result list,
so new nodes can be added easily. The dummy node initially gives the tail a memory space to point to.
This dummy node is efficient, since it is only temporary, and it is allocated in the stack.
The loop proceeds, removing one node from either ‘a’ or ‘b’ and adding it to the tail.
When the given lists are traversed the result is in dummy. next, as the values are allocated from next node of the dummy.
If both the elements are equal then remove both and insert the element to the tail.
Else remove the smaller element among both the lists.
*/
