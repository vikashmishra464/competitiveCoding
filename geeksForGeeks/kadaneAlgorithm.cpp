// Question Link: https://www.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1

// Question: 
// Given an integer array arr[]. Find the contiguous sub-array(containing at least one number) that has the maximum sum and return its sum.

// Examples:

// Input: arr[] = [1, 2, 3, -2, 5]
// Output: 9
// Explanation: Max subarray sum is 9 of elements (1, 2, 3, -2, 5) which is a contiguous subarray.
// Input: arr[] = [-1, -2, -3, -4]
// Output: -1
// Explanation: Max subarray sum is -1 of element (-1)
// Input: arr[] = [5, 4, 7]
// Output: 16
// Explanation: Max subarray sum is 16 of element (5, 4, 7)
// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ arr.size() ≤ 105
// -107 ≤ arr[i] ≤ 107


// Solution:

class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(vector<int> &arr) {
        int n=arr.size();
        int sum=0;
        int mx=arr[0];
        for(int i=0;i<n;i++){
            sum+=arr[i];
            mx=max(sum,mx);
            if(sum<0){
                sum=0;
            }
        }
        return mx;
    }
};