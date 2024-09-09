// Question Link:https://leetcode.com/problems/split-linked-list-in-parts/

// Question:
// Given the head of a singly linked list and an integer k, split the linked list into k consecutive linked list parts.

// The length of each part should be as equal as possible: no two parts should have a size differing by more than one. This may lead to some parts being null.

// The parts should be in the order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal to parts occurring later.

// Return an array of the k parts.

 

// Example 1:


// Input: head = [1,2,3], k = 5
// Output: [[1],[2],[3],[],[]]
// Explanation:
// The first element output[0] has output[0].val = 1, output[0].next = null.
// The last element output[4] is null, but its string representation as a ListNode is [].
// Example 2:


// Input: head = [1,2,3,4,5,6,7,8,9,10], k = 3
// Output: [[1,2,3,4],[5,6,7],[8,9,10]]
// Explanation:
// The input has been split into consecutive parts with size difference at most 1, and earlier parts are a larger size than the later parts.
 

// Constraints:

// The number of nodes in the list is in the range [0, 1000].
// 0 <= Node.val <= 1000
// 1 <= k <= 50

// Solution:

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n=0;
        if(k==1){
            return {head};
        }
        ListNode* temp=head;
        ListNode* dummy=new ListNode(0);
        while(temp){
            n++;
            temp=temp->next;
        }
        vector<ListNode*> ans(k);
        temp=head;
        int f=0;
        if(n<k){
            for(int i=0;i<n;i++){
                ans[i]=temp;
                temp=temp->next;
                ans[i]->next=NULL;
            }
        return ans;
        }
        int p=(n%k==0)?0:1;
        for(int i=0;i<k;i++){
            int l=n%k-i;
            int m=n/k;
            if(l>0){
                m=n/k+1; 
            }
            ans[f]=temp;
            for(int j=0;j<m-1;j++){
                temp=temp->next;
            }
            ListNode* t2=temp;
            temp=temp->next;
            t2->next=NULL;
            f++;
        }
        return ans;
    }
};