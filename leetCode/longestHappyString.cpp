// 1405. Longest Happy String
// Solved
// Medium
// Topics
// Companies
// Hint
// A string s is called happy if it satisfies the following conditions:

// s only contains the letters 'a', 'b', and 'c'.
// s does not contain any of "aaa", "bbb", or "ccc" as a substring.
// s contains at most a occurrences of the letter 'a'.
// s contains at most b occurrences of the letter 'b'.
// s contains at most c occurrences of the letter 'c'.
// Given three integers a, b, and c, return the longest possible happy string. If there are multiple longest happy strings, return any of them. If there is no such string, return the empty string "".

// A substring is a contiguous sequence of characters within a string.

 

// Example 1:

// Input: a = 1, b = 1, c = 7
// Output: "ccaccbcc"
// Explanation: "ccbccacc" would also be a correct answer.
// Example 2:

// Input: a = 7, b = 1, c = 0
// Output: "aabaa"
// Explanation: It is the only correct answer in this case.
 

// Constraints:

// 0 <= a, b, c <= 100
// a + b + c > 0

// Solution:

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>>p;
        if(a>0)
        p.push({a,'a'});
        if(b>0)
        p.push({b,'b'});
        if(c>0)
        p.push({c,'c'});

        string ans="";
        while(!p.empty()){
            auto[count,ch]=p.top();
            p.pop();
            if(ans.size()>=2 && ans[ans.size()-1]==ch && ans[ans.size()-2]==ch){
                if(p.empty()) break;
                auto [count2,ch2]=p.top();
                p.pop();
                ans.push_back(ch2);
                count2--;
                if(count2>0){
                    p.push({count2,ch2});
                }
            }
            else{
                count--;
                ans.push_back(ch);
                }
                if(count>0){
                    p.push({count,ch});
                }

        }
        return ans;
    }
};