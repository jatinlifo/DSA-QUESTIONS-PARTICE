// Given the head of a singly linked list, return the middle node of the linked list.

// If there are two middle nodes, return the second middle node
// Example 1:
// Input: head = [1,2,3,4,5]
// Output: [3,4,5]
// Explanation: The middle node of the list is node 3.
// Example 2:
// Input: head = [1,2,3,4,5,6]
// Output: [4,5,6]
// Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.



#include<iostream>

using namespace std;

class ListNode{
    public:

    int val;
    ListNode* next;

    ListNode(int data){
        val = data;
        next = nullptr;
    }
};

class LinkedList{
    public:

    ListNode* head;

    LinkedList(){
        head = nullptr;
    }

    void insertAtTail(int value)
    {
        ListNode* new_node = new ListNode(value);

        if(head == nullptr){
            head = new_node;
            return;
        }
        ListNode* temp = head;

        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = new_node;
    }

    void display() {
        ListNode* temp = head;

        while(temp != nullptr){
            cout<<temp->val<<"->";
            temp = temp->next;
        }
        cout<<"NULL";
    }

};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        
        ListNode* curr = head;
        int count = 0;

        while(curr != nullptr){
            count++;
            curr = curr->next;
        }
        int mid = count/2;
        while(mid != 0){
            head = head->next;
            mid--;
        }
        return head;
    }
};

int main ()
{
    LinkedList ll;
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(4);
    ll.insertAtTail(5);
    ll.insertAtTail(5);
    
    ll.display();

    cout<<endl;

    Solution obj;
    ll.head = obj.middleNode(ll.head);
    ll.display();

    return 0;
}