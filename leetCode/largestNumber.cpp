// Question Link: https://leetcode.com/problems/largest-number/description/?envType=daily-question&envId=2024-09-18
// Question:
// 179. Largest Number
// Solved
// Medium
// Topics
// Companies
// Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.

// Since the result may be very large, so you need to return a string instead of an integer.

 

// Example 1:

// Input: nums = [10,2]
// Output: "210"
// Example 2:

// Input: nums = [3,30,34,5,9]
// Output: "9534330"
 

// Constraints:

// 1 <= nums.length <= 100
// 0 <= nums[i] <= 109

// Solution:

class Solution {
public:
    static bool customCompare(string a, string b) {
        return (a + b) > (b + a);
    }
    string largestNumber(vector<int>& nums) {
        vector<string>nums2;
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums2.push_back(to_string(nums[i]));
        }
        sort(nums2.begin(), nums2.end(), customCompare);
        string ans="";
        for(auto i:nums2){
            ans+=i;
        }
        if(ans[0]=='0'){
            return "0";
        }
        return ans;
    }
};
