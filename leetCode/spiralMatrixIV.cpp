
// Question Link:https://leetcode.com/problems/spiral-matrix-iv/?envType=daily-question&envId=2024-09-09

// Question:You are given two integers m and n, which represent the dimensions of a matrix.

// You are also given the head of a linked list of integers.

// Generate an m x n matrix that contains the integers in the linked list presented in spiral order (clockwise), starting from the top-left of the matrix. If there are remaining empty spaces, fill them with -1.

// Return the generated matrix.

 

// Example 1:


// Input: m = 3, n = 5, head = [3,0,2,6,8,1,7,9,4,2,5,5,0]
// Output: [[3,0,2,6,8],[5,0,-1,-1,1],[5,2,4,9,7]]
// Explanation: The diagram above shows how the values are printed in the matrix.
// Note that the remaining spaces in the matrix are filled with -1.
// Example 2:


// Input: m = 1, n = 4, head = [0,1,2]
// Output: [[0,1,2,-1]]
// Explanation: The diagram above shows how the values are printed from left to right in the matrix.
// The last space in the matrix is set to -1.
 

// Constraints:

// 1 <= m, n <= 105
// 1 <= m * n <= 105
// The number of nodes in the list is in the range [1, m * n].
// 0 <= Node.val <= 1000

// Solution:
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> arr(m,vector<int>(n,-1));
        int top=0;
        int left=0;
        int right=n-1;
        int bottom=m-1;
        ListNode* temp=head;
        while(temp!=NULL && left<=right && top<=bottom){
            for(int i=left;i<=right && temp!=NULL;i++){
                arr[top][i]=temp->val;
                temp=temp->next;
            }
                top++;
            if(left<=right){
                for(int i=top;i<=bottom && temp!=NULL;i++){
                    arr[i][right]=temp->val;
                    temp=temp->next;
                }
                right--;
            }
            if(top<=bottom){
            for(int i=right;i>=left && temp!=NULL;i--){
                arr[bottom][i]=temp->val;
                temp=temp->next;
            }
                 bottom--;
            }
            if(left<=right){
            for(int i=bottom;i>=top && temp!=NULL;i--){
                arr[i][left]=temp->val;
                temp=temp->next;
            }
                left++;
            }
        }
        return arr;
    }
};
