// // Question Link:https://www.geeksforgeeks.org/problems/longest-prefix-suffix2527/1


// // Question:
// // Longest Prefix Suffix
// // Difficulty: HardAccuracy: 27.91%Submissions: 133K+Points: 8
// // Given a string of characters, find the length of the longest proper prefix which is also a proper suffix.

// // NOTE: Prefix and suffix can be overlapping but they should not be equal to the entire string.

// // Examples :

// // Input: str = "abab"
// // Output: 2
// // Explanation: "ab" is the longest proper prefix and suffix. 
// // Input: str = "aaaa"
// // Output: 3
// // Explanation: "aaa" is the longest proper prefix and suffix. 
// // Expected Time Complexity: O(|str|)
// // Expected Auxiliary Space: O(|str|)

// // Constraints:
// // 1 ≤ |str| ≤ 106
// // str contains lower case English alphabets

// Solution:

class Solution {
  public:
    int lps(string str) {
        vector<int>LPS(str.size(),0);
        int length=0;
        int i=1;
        while(i<str.size()){
            if(str[i]==str[length]){
                length++;
                LPS[i]=length;
                i++;
            }
            else{
                if(length>0){
                    length=LPS[length-1];
                }
                else{
                    LPS[i]=0;
                    i++;
                }
            }
        }
        return LPS[str.size()-1];
    }
};