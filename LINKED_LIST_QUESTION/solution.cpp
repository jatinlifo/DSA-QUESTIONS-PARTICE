// Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.
// Example 1:
// Input: head = [1,1,2]
// Output: [1,2]
// Example 2:

// Input: head = [1,1,2,3,3]
// Output: [1,2,3]
 
// Constraints:
// The number of nodes in the list is in the range [0, 300].
// -100 <= Node.val <= 100
// The list is guaranteed to be sorted in ascending order.

#include<iostream>
#include<vector>
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
        
        while(temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    void display() {
        ListNode* temp = head;

        while(temp != nullptr)
        {
            cout<<temp->val<<"-->";
            temp = temp->next;
        }
        cout<<"nullptr"<<endl;
    }
};

class Solution{
    public:

    ListNode* deleteDuplicates(ListNode* head)
    {
        ListNode* curr = head;

        while(curr != nullptr && curr->next != nullptr)
        {
            if(curr->val == curr->next->val)
            {
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                delete(temp);
            }
           else{
            curr = curr->next;
           }
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

    Solution obj;
    ll.head = obj.deleteDuplicates(ll.head);
    ll.display();

    return 0;
}