// Subarray range with given sum
// Difficulty: MediumAccuracy: 42.21%Submissions: 45K+Points: 4
// Given an unsorted array of integers arr[], and a target tar, determine the number of subarrays whose elements sum up to the target value.

// Examples:

// Input: arr[] = [10, 2, -2, -20, 10] , tar = -10
// Output: 3
// Explanation: Subarrays with sum -10 are: [10, 2, -2, -20], [2, -2, -20, 10] and [-20, 10].
// Input: arr[] = [1, 4, 20, 3, 10, 5] , tar = 33
// Output: 1
// Explanation: Subarray with sum 33 is: [20,3,10].
// Expected Time Complexity: O(n)
// Expected Auxilary Space: O(n)

// Constraints:
// 1 <= arr.size() <= 106
// -105 <= arr[i] <= 105
// -105 <= tar <= 105

// Solution :

class Solution {
  public:
    // Function to count the number of subarrays which adds to the given sum.
    int subArraySum(vector<int>& arr, int tar) {
        unordered_map<int,int>m;
        int sum=0;
        m[0]=1;
        int n=arr.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            int  prefix=sum-tar;
            if(m[prefix]>0){
                cnt+=m[prefix];
            }
            m[sum]++;
        }
        return cnt;
    
        
    }
};