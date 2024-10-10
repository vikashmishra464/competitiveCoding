// Max distance between same elements
// Difficulty: EasyAccuracy: 46.67%Submissions: 62K+Points: 2
// Given an array arr[] with repeated elements, the task is to find the maximum distance between two occurrences of an element.

// Note: You may assume that every input array has repetitions.

// Examples:

// Input: arr = [1, 1, 2, 2, 2, 1]
// Output: 5
// Explanation: distance for 1 is: 5-0 = 5, distance for 2 is : 4-2 = 2, So max distance is 5.
// Input: arr = [3, 2, 1, 2, 1, 4, 5, 8, 6, 7, 4, 2]
// Output: 10
// Explanation: maximum distance for 2 is 11-1 = 10, maximum distance for 1 is 4-2 = 2 ,maximum distance for 4 is 10-5 = 5, So max distance is 10.
// Expected Time Complexity :  O(n)
// Expected Auxilliary Space : O(n)

// Constraints:
// 1 <= arr.size() <= 106
// 1 <= arr[i] <= 109

// Solution:

class Solution {
  public:
    int maxDistance(vector<int> &arr) {
        unordered_map<int,pair<int,int>>m;
        for(int i=0;i<arr.size();i++){
            if(m.find(arr[i])!=m.end()){
                m[arr[i]].second=i;
            }
            else{
                m[arr[i]]={i,i};
            }
        }
        int mx=INT_MIN;
        for(auto i:m){
            mx=max(mx,i.second.second-i.second.first);
        }
        return mx;
    }
};