// Sort a k sorted doubly linked list
// Difficulty: EasyAccuracy: 55.57%Submissions: 19K+Points: 2
// Given a doubly linked list, each node is at most k-indices away from its target position. The problem is to sort the given doubly linked list. The distance can be assumed in either of the directions (left and right).

// Examples :

// Input: Doubly Linked List : 3 <-> 2 <-> 1 <-> 5 <-> 6 <-> 4 , k = 2
// Output: 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6

// Explanation: After sorting the given 2-sorted list is 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6.
// Input: Doubly Linked List : 5 <-> 6 <-> 7 <-> 3 <-> 4 <-> 4 , k = 3
// Output: 3 <-> 4 <-> 4 <-> 5 <-> 6 <-> 7

// Explanation: After sorting the given 3-sorted list is 3 <-> 4 <-> 4 <-> 5 <-> 6 <-> 7.
// Expected Time Complexity: O(n*logk)
// Expected Auxiliary Space: O(k)
// Constraints:
// 1 <= number of nodes <= 105
// 1 <= k < number of nodes
// 1 <= node->data <= 109

// Solution:

class Solution {
  public:
    // function to sort a k sorted doubly linked list
    DLLNode *sortAKSortedDLL(DLLNode *head, int k) {
        DLLNode* temp=head;
        priority_queue<int,vector<int>,greater<int>>p;
        for(int i=0;i<=k && temp!=NULL ;i++){
            p.push(temp->data);
            temp=temp->next;
        }
        DLLNode* ans=new DLLNode(p.top());
        DLLNode* t1=ans;
        p.pop();
        while(temp){
            p.push(temp->data);
            DLLNode* nw=new DLLNode(p.top());
            ans->next=nw;
            nw->prev=ans;
            ans=ans->next;
            p.pop();
            temp=temp->next;
        }
        while(!p.empty()){
            DLLNode* nw=new DLLNode(p.top());
            ans->next=nw;
            nw->prev=ans;
            ans=ans->next;
            p.pop();
        }
        return t1;
    }
};