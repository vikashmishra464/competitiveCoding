// Question Link:https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1

// Question:Missing And Repeating
// Difficulty: MediumAccuracy: 24.83%Submissions: 498K+Points: 4
// Given an unsorted array arr of of positive integers. One number 'A' from set {1, 2,....,n} is missing and one number 'B' occurs twice in array. Find numbers A and B.

// Examples

// Input: arr[] = [2, 2]
// Output: 2 1
// Explanation: Repeating number is 2 and smallest positive missing number is 1.
// Input: arr[] = [1, 3, 3] 
// Output: 3 2
// Explanation: Repeating number is 3 and smallest positive missing number is 2.
// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(1)

// Constraints:
// 2 ≤ n ≤ 105
// 1 ≤ arr[i] ≤ n

// Solution:

class Solution{
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int reapeated;
        for(int i=0;i<arr.size();i++){
            int idx=abs(arr[i])-1;
            if(arr[idx]<0){
                reapeated=abs(idx+1);
            }
            else{
                arr[idx]*=-1;
            }
        }
        int missing;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>=1){
               missing= i+1;
            }
        }
        return {reapeated,missing};
        
    }
};
