// Allocate Minimum Pages
// Difficulty: MediumAccuracy: 35.51%Submissions: 229K+Points: 4
// You are given an array arr[] of integers, where each element arr[i] represents the number of pages in the ith book. You also have an integer k representing the number of students. The task is to allocate books to each student such that:

// Each student receives atleast one book.
// Each student is assigned a contiguous sequence of books.
// No book is assigned to more than one student.
// The objective is to minimize the maximum number of pages assigned to any student. In other words, out of all possible allocations, find the arrangement where the student who receives the most pages still has the smallest possible maximum.

// Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).

// Examples:

// Input: arr[] = [12, 34, 67, 90], k = 2
// Output: 113
// Explanation: Allocation can be done in following ways:
// [12] and [34, 67, 90] Maximum Pages = 191
// [12, 34] and [67, 90] Maximum Pages = 157
// [12, 34, 67] and [90] Maximum Pages = 113.
// Therefore, the minimum of these cases is 113, which is selected as the output.
// Input: arr[] = [15, 17, 20], k = 5
// Output: -1
// Explanation: Allocation can not be done.
// Input: arr[] = [22, 23, 67], k = 1
// Output: 112
// Constraints:
// 1 <=  arr.size() <= 106
// 1 <= arr[i] <= 103
// 1 <= k <= 103 


// Solution:

  public:
    bool solve(vector<int>&arr,int page,int k){
        int cur=0;
        int child=0;
        for(int i=0;i<arr.size();i++){
            if(cur+arr[i]<=page){
                cur+=arr[i];
            }
            else{
                cur=arr[i];
                child++;
            }
        }
        child++;
        if(child<=k){
            return true;
        }
        return false;
        
    }
    int findPages(vector<int> &arr, int k) {
        int n=arr.size();
        if(n<k){
            return -1;
        }
        int sum=0;
        int maxi=arr[0];
        for(int i=0;i<n;i++){
            sum+=arr[i];
            maxi=max(arr[i],maxi);
        }
        int l=maxi;
        int r=sum;
        int ans=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(solve(arr,mid,k)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};