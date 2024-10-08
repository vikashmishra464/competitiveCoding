// Question Link:https://www.geeksforgeeks.org/problems/power-of-numbers-1587115620/1

// Question:Power Of Numbers
// Difficulty: MediumAccuracy: 20.22%Submissions: 314K+Points: 4
// Given a number and its reverse. Find that number raised to the power of its own reverse.
// Note: As answers can be very large, print the result modulo 109 + 7.

// Example 1:

// Input:
// N = 2, R = 2
// Output: 4
// Explanation: The reverse of 2 is 2 and after raising power of 2 by 2 we get 4 which gives remainder as 4 when divided by 1000000007.
// Example 2:

// Input:
// N = 12, R = 21
// Output: 864354781
// Explanation: The reverse of 12 is 21and 1221 when divided by 1000000007 gives remainder as 864354781.
// Your Task:
// You don't need to read input or print anything. You just need to complete the function pow() that takes two parameters N and R denoting the input number and its reverse and returns power of (N to R)mod(109 + 7).

// Expected Time Complexity: O(LogN).
// Expected Auxiliary Space: O(LogN).

// Constraints:
// 1 <= N <= 109

// Solution :

class Solution{
    public:
    //You need to complete this fucntion
    int mod=1e9+7;
    long long power(int N,int R)
    {
        
        if(R==0){
            return 1;
        }
        
        long long m = power(N, R / 2) % mod;
        if(R%2!=0){
            return ((m*m)%mod*(N%mod))%mod;
        }
        else{
            return (m*m)%mod;
        }
    }

};
