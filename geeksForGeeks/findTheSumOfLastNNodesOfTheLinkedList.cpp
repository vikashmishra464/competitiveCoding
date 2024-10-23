// Find the Sum of Last N nodes of the Linked List
// Difficulty: EasyAccuracy: 61.47%Submissions: 53K+Points: 2
// Given a single linked list, calculate the sum of the last n nodes.

// Note: It is guaranteed that n <= number of nodes.

// Examples:

// Input: Linked List: 5->9->6->3->4->10, n = 3

// Output: 17
// Explanation: The sum of the last three nodes in the linked list is 3 + 4 + 10 = 17.
// Input: Linked List: 1->2, n = 2

// Output: 3
// Explanation: The sum of the last two nodes in the linked list is 2 + 1 = 3.
// Constraints:
// 1 <= number of nodes, n <= 105
// 1 <= node->data <= 103

// Solution:

    int sumOfLastN_Nodes(struct Node* head, int n) {
        Node* temp=head;
        int i=0;
        for(i=0;i<n && temp;i++){
            temp=temp->next;
        }
        Node*slow=NULL;
        if(i==n){
            slow=head;
            while(temp){
                temp=temp->next;
                slow=slow->next;
            }
        }
        int sum=0;
        while(slow){
            sum+=slow->data;
            slow=slow->next;
        }
        return sum;
        
    }
};
