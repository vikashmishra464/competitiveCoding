// Question Link: https://leetcode.com/problems/minimum-time-difference/description/?envType=daily-question&envId=2024-09-16
// Question:
// 539. Minimum Time Difference
// Solved
// Medium
// Topics
// Companies
// Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference between any two time-points in the list.
 

// Example 1:

// Input: timePoints = ["23:59","00:00"]
// Output: 1
// Example 2:

// Input: timePoints = ["00:00","23:59","00:00"]
// Output: 0
 

// Constraints:

// 2 <= timePoints.length <= 2 * 104
// timePoints[i] is in the format "HH:MM".

// Solution:
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
            vector<int> vec(timePoints.size(),0);
            for(int i =0;i<timePoints.size();i++){
                string s = timePoints[i];
                int min=((s[0]-'0')*10 + (s[1]-'0'))*60 + (s[3]-'0')*10 + (s[4]-'0');
                vec[i]=min;
            }
            sort(vec.begin(),vec.end());
            int mn=INT_MAX;
            for(int i=1;i<vec.size();i++){
                int diff = abs(vec[i-1] - vec[i]);
                mn = min(mn, min(diff, 1440 - diff));
            }
            int n=vec.size();
            int diff = abs(vec[0] - vec[n-1]);
            mn = min(mn, min(diff, 1440 - diff));

        return mn;
    }
};



