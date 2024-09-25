// Question Link:https://www.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1Palindrome Linked List


// Question:
// Difficulty: MediumAccuracy: 41.48%Submissions: 334K+Points: 4
// Given a singly linked list of integers. The task is to check if the given linked list is palindrome or not.

// Examples:

// Input: LinkedList: 1->2->1->1->2->1
// Output: true
// Explanation: The given linked list is 1->2->1->1->2->1 , which is a palindrome and Hence, the output is true.

// Input: LinkedList: 1->2->3->4
// Output: false
// Explanation: The given linked list is 1->2->3->4, which is not a palindrome and Hence, the output is false.

// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(1) 
// Note: You should not use the recursive stack space as well

// Constraints:
// 1 <= number of nodes <= 105
// 1 ≤ node->data ≤ 103
// Question:

// Solution:

class Solution {
  public:
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head) {
        if (!head || !head->next) {
            return true;  // Empty list or single element list is a palindrome
        }

        Node* fast=head;
        Node*slow=head;
        Node*pre=NULL;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            pre=slow;
            slow=slow->next;
        }
        pre->next=NULL;
        Node*prev=NULL;
        while(slow){
            fast=slow->next;
            slow->next=prev;
            prev=slow;
            slow=fast;
            
        }
        Node*temp=head;
        while(temp && prev){
            if(temp->data!=prev->data){
                return false;
            }
            temp=temp->next;
            prev=prev->next;
        }
        return true;
    }
};