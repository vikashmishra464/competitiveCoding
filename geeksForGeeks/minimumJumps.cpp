// Question Link: https://www.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1

// Question:
// Given an array arr[] of non-negative integers. Each array element represents the maximum length of the jumps that can be made forward from that element. This means if arr[i] = x, then we can jump any distance y such that y ≤ x.
// Find the minimum number of jumps to reach the end of the array starting from the first element. If an element is 0, then you cannot move through that element.
// Note:  Return -1 if you can't reach the end of the array.

// Examples : 

// Input: arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}
// Output: 3 
// Explanation:First jump from 1st element to 2nd element with value 3. From here we jump to 5th element with value 9, and from here we will jump to the last. 
// Input: arr = {1, 4, 3, 2, 6, 7}
// Output: 2 
// Explanation: First we jump from the 1st to 2nd element and then jump to the last element.
// Input: arr = {0, 10, 20}
// Output: -1
// Explanation: We cannot go anywhere from the 1st element.
// Expected Time Complexity: O(n)
// Expected Space Complexity: O(1)

// Constraints:
// 0 ≤ arr[i] ≤ 105
// 2 ≤ arr.size() ≤ 106

// Solution:

class Solution {
  public:
    int minJumps(vector<int>& arr) {
        int i=0;
        int n=arr.size();
        int count=0;
        while(i<n-1){
            if(arr[i]==0){
                return -1;
            }
            
            count++;
            if(arr[i]+i>=n-1){
                return count;
            }
            int mx=arr[i+1]+i+1;
            int idx=i+1;
            for(int j=i+1; j<n&&j<=arr[i]+i;j++){
                if(mx<=arr[j]+j){
                    mx=arr[j]+j;
                    idx=j;
                }
                // if(j==n-1){
                //     return count;
                // }
            }
            i=idx;
            
        }
        return count;
    }
};