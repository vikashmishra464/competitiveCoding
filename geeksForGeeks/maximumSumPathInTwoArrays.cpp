// Question Link: https://www.geeksforgeeks.org/problems/max-sum-path-in-two-arrays/1
// Question:
// Given two sorted arrays of distinct integers arr1 and arr2. Each array may have some 
// elements in common with the other array. Find the maximum sum of a path from the 
// beginning of any array to the end of any array. You can switch from one array to 
// another array only at the common elements.

// Note:  When we switch from one array to other,  we need to consider the common element only once in the result.

// Examples : 

// Input: arr1 = [2, 3, 7, 10, 12] , arr2 = [1, 5, 7, 8]
// Output: 35
// Explanation: The path will be 1+5+7+10+12 = 35, where 1 and 5 come from arr2 and then 7 is common so we switch to arr1 and add 10 and 12.
// Input: arr1 = [1, 2, 3] , arr2[] = [3, 4, 5]
// Output: 15
// Explanation: The path will be 1+2+3+4+5=15.
// Expected Time Complexity: O(m + n)
// Expected Auxiliary Space: O(1)
// Constraints:
// 1 <= arr1.size(), arr2.size() <= 10^4
// 1 <= arr1[i], arr2[i] <= 10^5

// Solution: 
// Method 1:
// Step 1: Mark the common elements in both arrays (I converted them to negative).

// Step 2: Now, find the prefix sum up to the common elements, reset the prefix, 
//         and repeat the process with the remaining elements.

// Step 3: Traverse both arrays from the end. If you find that both elements are 
//         less than zero, add the maximum element to the sum. For the remaining elements, 
//         check the last element of the array accordingly.

// Time complexity: O(n+m)
// Space complexity: O(1)

class Solution
{
public:
    int maxPathSum(vector<int> &arr1, vector<int> &arr2)
    {
        int n = arr1.size();
        int m = arr2.size();
        int i = 0;
        int j = 0;
        while (i < n && j < m)
        {
            if (arr1[i] == arr2[j])
            {
                arr1[i] *= -1;
                arr2[j] *= -1;
                i++;
                j++;
            }
            else if (arr1[i] > arr2[j])
            {
                j++;
            }
            else
            {
                i++;
            }
        }
        int pre = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr1[i] > 0)
            {
                arr1[i] = pre + arr1[i];
                pre = arr1[i];
            }
            else
            {
                arr1[i] = (pre + (arr1[i] * -1)) * -1;
                pre = 0;
            }
        }
        pre = 0;
        for (int i = 0; i < m; i++)
        {
            if (arr2[i] > 0)
            {
                arr2[i] = pre + arr2[i];
                pre = arr2[i];
            }
            else
            {
                arr2[i] = (pre + (arr2[i] * -1)) * -1;
                pre = 0;
            }
        }
        int sum = 0;
        i = n - 1;
        j = m - 1;
        if (arr1[i] > 0 && arr2[j] > 0)
        {
            sum = max(arr1[i], arr2[j]);
        }
        else if (arr1[i] < 0 || arr2[j] < 0)
        {
            if (arr1[i] < 0 && arr2[j] > 0)
            {
                sum = arr2[j];
            }
            else if (arr1[i] > 0 && arr2[j] < 0)
            {
                sum = arr1[i];
            }
        }
        while (i >= 0 && j >= 0)
        {
            if (arr1[i] < 0 && arr2[j] < 0)
            {
                sum += max(arr1[i] * -1, arr2[j] * -1);
                i--;
                j--;
            }
            else if (arr2[j] > 0)
            {
                j--;
            }
            else
            {
                i--;
            }
        }
        return sum;
    }
};

// Method 2:

// Step 1: Traverse through both arrays and keep track of the prefix sum for each array in separate variables.

// Step 2: When the elements are equal, add the maximum prefix sum plus the current element to the global sum (sum = max(prefixSum1, prefixSum2) + currentElement).

// Time complexity: O(n+m)
// Space complexity: O(1)

class Solution {
  public:
    int maxPathSum(vector<int> &arr1, vector<int> &arr2) {
        int n=arr1.size();
        int m=arr2.size();
        int i=0;int j=0;
        int presum1=0;
        int presum2=0;
        int ans=0;
        while(i<n && j<m){
            if(arr1[i]==arr2[j]){
                ans+=max(presum1+arr1[i],presum2+arr2[j]);
                presum1=0;
                presum2=0;
                i++;
                j++;
            }
            else if(arr1[i]>arr2[j]){
                presum2+=arr2[j];
                j++;
            }
            else{
                presum1+=arr1[i];
                i++;
            }
        }
        for(int k=i;k<n;k++){
            presum1+=arr1[k];
        }
        for(int k=j;k<m;k++){
            presum2+=arr2[k];
        }
        ans+=max(presum1,presum2);
        return ans;
    }
};
  