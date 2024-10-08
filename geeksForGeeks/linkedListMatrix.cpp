// Question Link:https://www.geeksforgeeks.org/problems/linked-list-matrix/1
// Question:
// Linked List Matrix
// Difficulty: EasyAccuracy: 67.33%Submissions: 14K+Points: 2
// Given a Matrix mat of n*n size. Your task is constructing a 2D linked list representation of the given matrix.

// Input: mat = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
// Output: 

// Input: mat = [[23, 28], [23, 28]]
// Output:

// Expected Time Complexity: O(n2)
// Expected Space Complexity: O(n2)

// Constraints:
// 1 <= mat.size() <=15
// 1 <= mat[i][j] <=104

// Solution:

class Solution {
  public:
    Node* constructLinkedMatrix(vector<vector<int>>& mat) {
        
        Node*head=NULL;
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<Node*>>nrr(n,vector<Node*>(m,NULL));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                nrr[i][j]=new Node(mat[i][j]);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==n-1 || j==m-1){
                    if(i+1<n && j==m-1){
                        nrr[i][j]->down=nrr[i+1][j];
                    }
                    else if(i==n-1 && j+1<m){
                        nrr[i][j]->right=nrr[i][j+1];
                    }
                }
                else{
                    nrr[i][j]->right=nrr[i][j+1];
                    nrr[i][j]->down=nrr[i+1][j];
                }
            }
        }
        return nrr[0][0];
    }
};
