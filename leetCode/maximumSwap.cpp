// 670. Maximum Swap
// Solved
// Medium
// Topics
// Companies
// You are given an integer num. You can swap two digits at most once to get the maximum valued number.

// Return the maximum valued number you can get.

 

// Example 1:

// Input: num = 2736
// Output: 7236
// Explanation: Swap the number 2 and the number 7.
// Example 2:

// Input: num = 9973
// Output: 9973
// Explanation: No swap.
 

// Constraints:

// 0 <= num <= 108

// Solution:

class Solution {
public:
    int maximumSwap(int num) {
        int n = num;
        vector<int> arr;
        int i = 0;
        priority_queue<pair<int, int>> p;
        while (n) {
            arr.push_back(n % 10);
            p.push({n % 10, i++});
            n = n / 10;
        }

        int s = arr.size() - 1;
        int k = s;
        while (!p.empty()) {

            int val = p.top().first;
            int idx = p.top().second;
            if (val != arr[k]) {
                while (p.top().first == val) {
                    idx = p.top().second;
                    p.pop();
                }
                swap(arr[k], arr[idx]);
                break;
            }
            k--;
            p.pop();
        }
        int l = 0;
        int mul = 10;
        for (i = s; i >= 0; i--) {
            l = l * 10 + arr[i];
        }
        return l;
    }
};