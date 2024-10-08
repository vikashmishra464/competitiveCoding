// Question:
// Find the largest pair sum in an array of distinct integers.

// Examples :

// Input: arr[] = [12, 34, 10, 6, 40]
// Output: 74
// Explanation: Sum of 34 and 40 is the largest, i.e, 34 + 40 = 74.
// Input: arr[] = [10, 20, 30]
// Output: 50
// Explanation: 20 + 30 = 50.
// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(1)

// Constraints:
// 2 ≤ arr.size() ≤ 106
// 0 ≤ arr[i] ≤ 106a

// Solution:

class Solution {
  public:
    int pairsum(vector<int> &arr) {
        int f=0;
        int s=-1;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>arr[f]){
                if( s==-1 || arr[f]>=arr[s]){
                    s=f;
                }
                f=i;
            }
            else if(arr[i]<arr[f] && arr[s]<arr[i]){
                s=i;
            }
        }
        return arr[f]+arr[s];
    }
};