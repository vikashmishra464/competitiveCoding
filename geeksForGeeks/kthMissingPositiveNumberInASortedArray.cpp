// Kth Missing Positive Number in a Sorted Array
// Difficulty: MediumAccuracy: 60.89%Submissions: 9K+Points: 4
// Given a sorted array of distinct positive integers arr[], we need to find the kth positive number that is missing from arr[].  

// Examples :

// Input: arr[] = [2, 3, 4, 7, 11], k = 5
// Output: 9
// Explanation: Missing are 1, 5, 6, 8, 9, 10… and 5th missing number is 9.
// Input: arr[] = [1, 2, 3], k = 2
// Output: 5
// Explanation: Missing are 4, 5, 6… and 2nd missing number is 5.
// Input: arr[] = [3, 5, 9, 10, 11, 12], k = 2
// Output: 2
// Explanation: Missing are 1, 2, 4, 6… and 2nd missing number is 2.
// Constraints:
// 1 <= arr.size() <= 105
// 1 <= k <= 105
// 1 <= arr[i]<= 106

// Solution:
class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        int l=0;
        int r=arr.size()-1;
        int pos=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(arr[mid]-(mid+1)>=k){
                pos=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        if(pos==-1){
            pos=arr.size();
        }
        int current=(pos-1<0)?0:arr[pos-1];    
        int dif=k-(current-(pos));
        int ans=current+dif;
        
        return ans;
    }
};