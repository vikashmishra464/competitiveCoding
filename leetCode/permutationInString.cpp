// 567. Permutation in String
// Solved
// Medium
// Topics
// Companies
// Hint
// Given two strings s1 and s2, return true if s2 contains a 
// permutation
//  of s1, or false otherwise.

// In other words, return true if one of s1's permutations is the substring of s2.

 

// Example 1:

// Input: s1 = "ab", s2 = "eidbaooo"
// Output: true
// Explanation: s2 contains one permutation of s1 ("ba").
// Example 2:

// Input: s1 = "ab", s2 = "eidboaoo"
// Output: false
 

// Constraints:

// 1 <= s1.length, s2.length <= 104
// s1 and s2 consist of lowercase English letters.

// Solution:

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()){
            return false;
        }
        unordered_map<char,int>m1;
        unordered_map<char,int>m2;
        for(auto i:s1){
            m1[i]++;
        }
        int n=s2.size();
        int unique=m1.size();
        int cnt=0;
        int ws=s1.size();
        int i=0;
        int j=0;
        for(j=0;j<ws;j++){
            m2[s2[j]]++;    
            if(m2[s2[j]]==m1[s2[j]]){
                cnt++;
            }
            // cout<<s2[j]<<" "<<cnt<<endl;
        }
        if(cnt==unique){
            return true;
        }
        for(j=ws;j<n;j++){
            if(m1[s2[i]]==m2[s2[i]]){
                cnt--;
            }
            m2[s2[i]]--;
            // cout<<s2[i]<<" "<<cnt<<endl;
            i++;
            m2[s2[j]]++;
            if(m2[s2[j]]==m1[s2[j]]){
                cnt++;
            }
            // cout<<s2[j]<<" "<<cnt<<endl;
            if(cnt==unique){
                return true;
            }
        }
        return false;
    }
};