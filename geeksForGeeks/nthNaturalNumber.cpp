// Question Link: https://www.geeksforgeeks.org/problems/nth-natural-number/1

// Question:
// Given a positive integer n. You have to find nth natural number after removing all the numbers containing the digit 9.

// Examples :

// Input: n = 8
// Output: 8
// Explanation: After removing natural numbers which contains digit 9, first 8 numbers are 1,2,3,4,5,6,7,8 and 8th number is 8.
// Input: n = 9
// Output: 10
// Explanation: After removing natural numbers which contains digit 9, first 9 numbers are 1,2,3,4,5,6,7,8,10 and 9th number is 10.
// Expected Time Complexity: O(logn)
// Expected Auxiliary Space: O(1)


// Constraints:
// 1 ≤ n ≤ 109




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
            int mx=arr[i+1]+i+1;
            int idx=i+1;
            for(int j=i+1; j<n&&j<=arr[i]+i;j++){
                if(mx<=arr[j]+j){
                    mx=arr[j]+j;
                    idx=j;
                }
                if(j==n-1){
                    return count;
                }
            }
            i=idx;
            
        }
        return count;
    }
};