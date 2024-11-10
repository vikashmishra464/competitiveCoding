// 3097. Shortest Subarray With OR at Least K II
// Solved
// Medium
// Topics
// Companies
// Hint
// You are given an array nums of non-negative integers and an integer k.

// An array is called special if the bitwise OR of all of its elements is at least k.

// Return the length of the shortest special non-empty 
// subarray
//  of nums, or return -1 if no special subarray exists.

 

// Example 1:

// Input: nums = [1,2,3], k = 2

// Output: 1

// Explanation:

// The subarray [3] has OR value of 3. Hence, we return 1.

// Example 2:

// Input: nums = [2,1,8], k = 10

// Output: 3

// Explanation:

// The subarray [2,1,8] has OR value of 11. Hence, we return 3.

// Example 3:

// Input: nums = [1,2], k = 0

// Output: 1

// Explanation:

// The subarray [1] has OR value of 1. Hence, we return 1.

 

// Constraints:

// 1 <= nums.length <= 2 * 105
// 0 <= nums[i] <= 109
// 0 <= k <= 109

// Solution:

class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int i=0;
        int n=nums.size();
        int f=0;
        int mn=INT_MAX;
        int j=0;
        bool b=false;
        vector<int>bitcount(32,0);
        for(i=0;i<n;i++){
            int cur=nums[i];
            int idx=0;
            while(cur>0){
                bitcount[idx]+=cur&1;
                cur=cur>>1;
                idx++;
            }
            f|=nums[i];
            while(j<=i && f>=k){
                b=true;
                // cout<<j<<"  "<<i<<endl;
                mn=min(mn,i-j+1);
                int cur=nums[j];
                int pos=0;
                while(cur>0){
                    bitcount[pos]-=cur&1;
                    cur=cur>>1;
                    pos++;
                }
                int newOR=0;
                for(int i=0;i<32;i++){
                    if(bitcount[i]>0){
                        newOR|=(1<<i);
                    }
                }
                f=newOR;
                // cout<<f<<endl;
                j++;
            }
        }
        if(b==false){
            return -1;
        }
        return mn;

    }
};