// Question Link:https://www.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1

// Question:

// Sort 0s, 1s and 2s
// Difficulty: EasyAccuracy: 50.58%Submissions: 681K+Points: 2
// Given an array arr containing only 0s, 1s, and 2s. Sort the array in ascending order.

// Examples:

// Input: arr[]= [0, 2, 1, 2, 0]
// Output: 0 0 1 2 2
// Explanation: 0s 1s and 2s are segregated into ascending order.
// Input: arr[] = [0, 1, 0]
// Output: 0 0 1
// Explanation: 0s 1s and 2s are segregated into ascending order.
// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= arr.size() <= 106
// 0 <= arr[i] <= 24


// Solution

class Solution {
  public:
    void sort012(vector<int>& arr) {
        int zero=0;
        int one=0;
        int two=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0){
                zero++;
            }
            else if(arr[i]==1){
                one++;
            }
            else{
                two++;
            }
        }
        int k=0;
        for(int i=0;i<zero;i++)arr[k++]=0;
        for(int i=0;i<one;i++)arr[k++]=1;
        for(int i=0;i<two;i++)arr[k++]=2;
    }
};

