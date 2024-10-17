// Split Linked List Alternatingly
// Difficulty: EasyAccuracy: 42.46%Submissions: 22K+Points: 2
// Given a singly linked list's head. Your task is to complete the function alternatingSplitList() that splits the given linked list into two smaller lists. The sublists should be made from alternating elements from the original list.
// Note: 

// The sublist should be in the order with respect to the original list.
// Your have to return an array containing the both sub-linked lists.
// Examples:

// Input: LinkedList = 0->1->0->1->0->1
// Output: 0->0->0 , 1->1->1
// Explanation: After forming two sublists of the given list as required, we have two lists as: 0->0->0 and 1->1->1.

// Input: LinkedList = 2->5->8->9->6
// Output: 2->8->6 , 5->9
// Explanation: After forming two sublists of the given list as required, we have two lists as: 2->8->6 and 5->9.
// Input: LinkedList: 7 
// Output: 7 , <empty linked list>


// Soltuion:
class Solution {
  public:
    // Function to split a linked list into two lists alternately
    vector<Node*> alternatingSplitList(struct Node* head) {
        Node*first=head;
        Node*second=new Node(0);
        Node* sec=second;
        Node* temp=head;
        while(temp){
            second->next=temp->next;
            second=second->next;
            if(temp->next){
            temp->next=temp->next->next;
            }
            temp=temp->next;
        }
        return {first,sec->next};
    }
};