// Question Link:https://leetcode.com/problems/shortest-palindrome/description/?envType=daily-question&envId=2024-09-20
// Question:
// 214. Shortest Palindrome
// Solved
// Hard
// Topics
// Companies
// You are given a string s. You can convert s to a 
// palindrome
//  by adding characters in front of it.

// Return the shortest palindrome you can find by performing this transformation.

 

// Example 1:

// Input: s = "aacecaaa"
// Output: "aaacecaaa"
// Example 2:

// Input: s = "abcd"
// Output: "dcbabcd"
 

// Constraints:

// 0 <= s.length <= 5 * 104
// s consists of lowercase English letters only.

// Solution:
class Solution {
public:
    string shortestPalindrome(string s) {
        string rev=s;
        reverse(s.begin(),s.end());
        string kmp=rev+"_"+s;
        cout<<rev<<endl<<s<<endl;
        cout<<kmp;
        vector<int>LPS(kmp.size(),0);
        int i=1;
        int length=0;

        while(i<kmp.size()){
            if(kmp[i]==kmp[length]){
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
        // for(auto i: LPS){
        //     cout<<i<<" "; 
        // }
        string f=rev.substr(LPS[kmp.size()-1]);
        reverse(f.begin(),f.end());
        string res=f+rev;
        return  res;

    }
};