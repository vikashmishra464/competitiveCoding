// Question Link:https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/description/?envType=daily-question&envId=2024-10-01

// Question:
// 1497. Check If Array Pairs Are Divisible by k
// Solved
// Medium
// Topics
// Companies
// Hint
// Given an array of integers arr of even length n and an integer k.

// We want to divide the array into exactly n / 2 pairs such that the sum of each pair is divisible by k.

// Return true If you can find a way to do that or false otherwise.

 

// Example 1:

// Input: arr = [1,2,3,4,5,10,6,7,8,9], k = 5
// Output: true
// Explanation: Pairs are (1,9),(2,8),(3,7),(4,6) and (5,10).
// Example 2:

// Input: arr = [1,2,3,4,5,6], k = 7
// Output: true
// Explanation: Pairs are (1,6),(2,5) and(3,4).
// Example 3:

// Input: arr = [1,2,3,4,5,6], k = 10
// Output: false
// Explanation: You can try all possible pairs to see that there is no way to divide arr into 3 pairs each with sum divisible by 10.
 

// Constraints:

// arr.length == n
// 1 <= n <= 105
// n is even.
// -109 <= arr[i] <= 109
// 1 <= k <= 105

// Solution:

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int>bucket(k,0);
        for(int i=0;i<arr.size();i++){
            bucket[(arr[i]%k+k)%k]++;
        }
        for(int i=0;i<k;i++){
            if(i==0){
                if(bucket[0]%2!=0){
                    return false;
                }
            }
            else if(bucket[i]!=bucket[k-i]){
                return false;
            }
        }
        return true;
    }
};

