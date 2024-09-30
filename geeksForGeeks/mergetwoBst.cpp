// Question Link:https://www.geeksforgeeks.org/problems/merge-two-bst-s/1
// Question:
// Merge two BST 's
// Difficulty: MediumAccuracy: 64.95%Submissions: 82K+Points: 4
// Given two BSTs, return elements of merged BSTs in sorted form.

// Examples :

// Input:
// BST1:
//        5
//      /   \
//     3     6
//    / \
//   2   4  
// BST2:
//         2
//       /   \
//      1     3
//             \
//              7
//             /
//            6
// Output: 1 2 2 3 3 4 5 6 6 7
// Explanation: After merging and sorting the two BST we get 1 2 2 3 3 4 5 6 6 7.
// Input:
// BST1:
//        12
//      /   
//     9
//    / \    
//   6   11
// BST2:
//       8
//     /  \
//    5    10
//   /
//  2
// Output: 2 5 6 8 9 10 11 12
// Explanation: After merging and sorting the two BST we get 2 5 6 8 9 10 11 12.
// Expected Time Complexity: O((m+n)*log(m+n))
// Expected Auxiliary Space: O(Height of BST1 + Height of BST2 + m + n)

// Constraints:
// 1 ≤ Number of Nodes, value of nodes ≤ 105

// solution
class Solution {
  public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    void pre(Node * root ,vector<int>&a){
        if(root!=NULL){
            pre(root->left,a);
            a.push_back(root->data);
            pre(root->right,a);
        }
    }
    vector<int> merge(Node *root1, Node *root2) {
        vector<int>v1;
        vector<int>v2;
        pre(root1,v1);
        pre(root2,v2);
        vector<int>ans;
        int i=0;int j=0;
        while(i<v1.size() && j<v2.size()){
            if(v1[i]<=v2[j]){
                ans.push_back(v1[i]);
                i++;
            }
            else{
                ans.push_back(v2[j]);
                j++;
            }
        }
        while(i<v1.size()){
            ans.push_back(v1[i]);
            i++;
        }
        while(j<v2.size()){
                ans.push_back(v2[j]);
                j++;
        }
        return ans;
    }
};