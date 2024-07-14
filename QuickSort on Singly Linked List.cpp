#include <bits/stdc++.h>
using namespace std;
/*
Given a linked list, apply the Quick sort algorithm to sort the linked list.
The important things about implementation are,
that it changes pointers rather than swapping data.
*/
struct Node {
    int data;
    Node* next;
};
// Function to insert a node at the beginning of linked list
void push_node(Node*& head_ref, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = head_ref;
    head_ref = new_node;
}
// Function to print linked list
void print_list(Node* ptr) {
    while(ptr != NULL) {
        cout << ptr->data << " " ;
        ptr = ptr->next;
    }
    cout << endl;
}
// Returns the last node of the list
Node* get_tail(Node* curr) {
    while(curr != NULL && curr->next != NULL)
        curr = curr->next;
    return curr;
}


// Partitions the list taking the last element as the pivot
Node* partition_take_last_node(Node* head, Node* End, Node*& new_head, Node*& new_end) {
    Node* pivot = End;
    Node* prev = NULL, *curr = head, *tail = pivot;

    // during partition, both the head and end of the list might change is updated
    // in the new head and new end variables
    while(curr != pivot) {
        if(curr->data < pivot->data) {
            // first node that has a value less than the pivot
            // becomes the new head
            if(new_head == NULL) {
                new_head = curr;
            }
            prev = curr;
            curr = curr->next;
        } else { // if curr node is greater than pivot
            // move curr node to next of tail, and change tail
            if(prev)
                prev->next = curr->next;
            Node* temp = curr->next;
            curr->next = NULL;
            tail->next = curr;
            tail = curr;
            curr = temp;
        }
    }
    // if pivot data is the smallest element in the current list
    // pivot becomes the head
    if(new_head == NULL)
        new_head = pivot;
    // update new end to the current last node
    new_end = tail;
    // return the pivot node
    return pivot;
}
// here the sorting happens exclusive of the end node
Node* quick_sort_recur(Node* head, Node* End) {
    // base condition
    if(!head || head == End)
        return head;

    Node* new_head = NULL, *new_end = NULL;
    // partition the list, new head and new end will be updated by the partition function
    Node* pivot = partition_take_last_node(head, End, new_head, new_end);
    // if pivot is the smallest element - no need to recur for the left part
    if(new_head != pivot) {
        // set the node before the pivot node as null
         Node* temp = new_head;
         while(temp->next != pivot)
            temp = temp->next;
         temp->next = NULL;
         // Recur for the list before pivot
         new_head = quick_sort_recur(new_head, temp);
         // change next of last node of the left half to pivot
         temp = get_tail(new_head);
         temp->next = pivot;
    }
    // recur for the list after the pivot element
    pivot->next = quick_sort_recur(pivot->next, new_head);

    return new_head;
}
// The main for quick sort, this is a wrapper over
// recursive function quick sort recur
void quick_sort(Node*& head_ref) {
    head_ref = quick_sort_recur(head_ref, get_tail(head_ref));

    return;
}

int main()
{
    Node* ptr = NULL;
    push_node(ptr, 5);
    push_node(ptr, 20);
    push_node(ptr, 4);
    push_node(ptr, 3);
    push_node(ptr, 30);

    cout << "Linked list before sorting" << endl;
    print_list(ptr);

    // function call
    quick_sort(ptr);

    cout << "Linked list after sorting" << endl;
    print_list(ptr);

    /*
        Time Complexity: O(N * log N), It takes O(N2) time in the worst case and O(N log N) in the average or best case.
        Auxiliary Space: O(N), As extra space is used in the recursion call stack.
    */


    return 0;
}
/*
- Call partition function to get a pivot node placed at its correct position
    In the partition function, the last element is considered a pivot
    Then traverse the current list and if a node has a value greater than the pivot,
        then move it after the tail. If the node has a smaller value, then keep it at its current position.
    Return pivot node
- Find the tail node of the list which is on the left side of the pivot and recur for the left list
- Similarly, after the left side, recur for the list on the right side of the pivot
- Now return the head of the linked list after joining the left and the right list, as the whole linked list is now sorted
*/
