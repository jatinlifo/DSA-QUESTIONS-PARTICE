// Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.
// Example 1:

// Input: head = [1,2,6,3,4,5,6], val = 6
// Output: [1,2,3,4,5]
// Example 2:

// Input: head = [], val = 1
// Output: []
// Example 3:

// Input: head = [7,7,7,7], val = 7
// Output: []
 

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

class Solution{
    public:

    ListNode* deleteElements(ListNode* head, int value) {
        
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* temp;

        while(curr != nullptr){
            
            if(curr->val == value){
                temp = curr;
                curr = curr->next;
                delete(temp);
                if(prev != nullptr){
                    prev->next = curr;
                }
                else{
                    head = curr;
                }
            }
            else{
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }

};

int main () {

    LinkedList ll;
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(6);
    ll.insertAtTail(5);
    ll.insertAtTail(4);
    ll.insertAtTail(6);

    ll.display();

    cout<<"After deleteting element "<<endl;
    
    Solution obj;
    int value;
    cout<<"Enter the  value for delete the given LL : ";
    cin>>value;
    ll.head = obj.deleteElements(ll.head,value);

    ll.display();

    return 0;
}