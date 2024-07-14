#include <bits/stdc++.h>
using namespace std;
/*
##Amazon##
Given a singly linked list containing n nodes. Modify the value of first half nodes such
that 1st node’s new value is equal to the last node’s value minus first node’s current value,
2nd node’s new value is equal to the second last node’s value minus 2nd node’s current value,
likewise for first half nodes. If n is odd then the value of the middle node remains unchanged.
(No extra memory to be used).

Examples:

Input : 10 -> 4 -> 5 -> 3 -> 6
Output : 4 -> 1 -> 5 -> 3 -> 6

Input : 2 -> 9 -> 8 -> 12 -> 7 -> 10
Output : -8 -> 2 -> -4 -> 12 -> 7 -> 10
*/

struct Node {
    int data;
    Node* next;
};

// Function -> to insert a node at the beginning
void Push(Node*& head_ref, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = head_ref;
    head_ref = new_node;
}

// Split the nodes of the given list into front and back halves, and return the 2 lists
    // uses the fast/slow pointer
void front_and_back_split(Node* head, Node*& front_ref, Node*& back_ref) {
    Node* slow, *fast;
    slow = head;
    fast = head->next;

    // fast 2 nodes, and slow one node
    while(fast != NULL) {
        fast = fast->next;
        if(fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    // slow is before mid point, so split it in 2 at the point
    front_ref = head;
    back_ref = slow->next;
    slow->next = NULL;
}

// Function -> to reverse the list
void reverse_list(Node*& head_ref) {
    Node* current, *prev, *next;
    current = head_ref;
    prev = NULL;

    while(current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head_ref = prev;
}

// perform the required subtraction operation on the 1st half
void modify_contents_of_1st_half(Node* front_, Node* back_) {
    // Traversing both lists
    while(back_ != NULL) {
        // subtraction operation and node data modification
        front_->data = front_->data - back_->data;
        front_ = front_->next;
        back_ = back_->next;
    }
}

// Function -> to concatenate the 2nd(back) at the end of 1st(front)
    // returns the head of the new list
Node* concat_front_and_back(Node* front_, Node* back_) {
    if(front_ == NULL)
        return back_;

    Node* head = front_;

    while(front_->next != NULL) {
        front_ = front_->next;
    }
    front_->next = back_;
    return head;
}

// Function -> To modify the contents of this list --> MAIN FUNCTION
Node* modify_list(Node* ptr) {
    // if list is empty
    if(!ptr || ptr->next == NULL)
        return ptr;

    Node* Front, *Back;
    // call -> split list into 2 halves front and back lists
    front_and_back_split(ptr, Front, Back);
    // call -> reverse 2nd(back)
    reverse_list(Back);
    // call -> modify the contents of 1st half
    modify_contents_of_1st_half(Front, Back);
    // call -> again reverse 2nd list
    reverse_list(Back);
    // concatenating the 2nd list to end of 1st list
    ptr = concat_front_and_back(Front, Back);
    // pointer to modified
    return ptr;
}

// Function -> print list
void print_list(Node* head) {
    if(!head)
        return;
    while(head->next != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << head->data << endl;
}

int main()
{
    Node* head_ref = NULL;

    // Creating the list
    Push(head_ref, 10);
    Push(head_ref, 7);
    Push(head_ref, 12);
    Push(head_ref, 8);
    Push(head_ref, 9);
    Push(head_ref, 2);

    head_ref = modify_list(head_ref);

    cout << "List After Modification :)" << endl;
    cout << "Modified list : " << endl;
    print_list(head_ref);

    // output : -8 -> 2 -> -4 -> 12 -> 7 -> 10
    // Time complexity : O(n)
    // Space complexity : O(1)


    return 0;
}
