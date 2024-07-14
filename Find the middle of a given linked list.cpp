#include <bits/stdc++.h>
using namespace std;
/*
Easy *
Auxiliary Given a singly linked list, find the middle of the linked list.
# For example, if the given linked list is 1->2->3->4->5 then the output should be 3.
If there are even nodes, then there would be two middle nodes,
we need to print the second middle element.
# For example, if the given linked list is 1->2->3->4->5->6 then the output should be 4.
*/
class NodeOperation
{
public:
    // define node
    struct Node {
        int data;
        Node* next;
    };
    // Push function
    void pushNode(Node*& head, int newData) {
        Node* newNode = new Node();
        newNode->data = newData;
        newNode->next = head;
        head = newNode;
    }
    // print function
    void printNode(Node* head) {
        while(head != NULL) {
            cout << head->data << "->";
            head = head->next;
        }
        cout << "NULL" << endl;
    }
    // function get length
    int getLen(Node* head) {
        int len = 0;
        Node* temp = head;
        while(temp) {
            len++;
            temp = temp->next;
        }
        return len;
    }
    // function print middle
    void printMiddle(Node* head) {
        if(head) {
            int len = getLen(head);
            Node* temp = head;

            int middleIndex = len / 2;
            while(middleIndex--) {
                temp = temp->next;
            }
            cout << "The middle element is [ " << temp->data << " ]" << endl;
        }
    }
};

int main()
{
    NodeOperation* temp = new NodeOperation();
    NodeOperation::Node* head = NULL;

    for(int i=5; i>0; i--){
        temp->pushNode(head, i);
        temp->printNode(head);
        temp->printMiddle(head);
    }

    // Time Complexity: O(n) => n is number of nodes in linked list
    // Space Complexity: O(1)

    return 0;
}
