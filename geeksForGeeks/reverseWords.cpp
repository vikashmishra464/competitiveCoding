// Question Link:https://www.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1

// Question:
// Reverse Words
// Difficulty: EasyAccuracy: 56.08%Submissions: 322K+Points: 2
// Given a String str, reverse the string without reversing its individual words. Words are separated by dots.

// Note: The last character has not been '.'. 

// Examples :

// Input: str = i.like.this.program.very.much
// Output: much.very.program.this.like.i
// Explanation: After reversing the whole string(not individual words), the input string becomes much.very.program.this.like.i
// Input: str = pqr.mno
// Output: mno.pqr
// Explanation: After reversing the whole string , the input string becomes mno.pqr
// Expected Time Complexity: O(|str|)
// Expected Auxiliary Space: O(|str|)

// Constraints:
// 1 <= |str| <= 105

//Solution:

class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        string ans="";
        string k="";
        for(auto i:str){
            if(i!='.'){
                k+=i;
            }
            else{
                ans='.'+k+ans;
                k="";
            }
        }
        ans=k+ans;
        return ans;
    }
};

