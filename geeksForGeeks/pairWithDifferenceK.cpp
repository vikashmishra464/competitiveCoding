// Pairs with difference k
// Difficulty: EasyAccuracy: 22.41%Submissions: 30K+Points: 2
// Given an array arr[] of positive integers. Find the number of pairs of integers whose difference equals a given number k.
// Note: (a, b) and (b, a) are considered the same. Also, the same numbers at different indices are considered different.

// Examples:

// Input: arr[] = [1, 5, 3, 4, 2], k = 3
// Output: 2
// Explanation: There are 2 pairs with difference 3,the pairs are {1, 4} and {5, 2} 
// Input: arr[] = [8, 12, 16, 4, 0, 20], k = 4
// Output: 5
// Explanation: There are 5 pairs with difference 4, the pairs are {0, 4}, {4, 8}, {8, 12}, {12, 16} and {16, 20}.
// Constraints:
// 1 <= arr.size() <= 106
// 1 <= k <= 106
// 1 <= arri <= 106

// Solution:
class Solution {
  public:
    /* Returns count of pairs with difference k  */
    int countPairsWithDiffK(vector<int>& arr, int k) {
        unordered_map<int,int>m;
        int cnt=0;
        for(int i=0;i<arr.size();i++){
            if(m.find(arr[i])!=m.end()){
                cnt+=m[arr[i]];
            }
            m[-1*(k-arr[i])]++;
            m[arr[i]+k]++;
            
        }
        return cnt;
    }
};