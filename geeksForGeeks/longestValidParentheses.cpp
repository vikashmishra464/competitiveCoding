// Question Link:https://www.geeksforgeeks.org/problems/longest-valid-parentheses5657/1

// Question:
// Longest valid Parentheses
// Difficulty: HardAccuracy: 26.13%Submissions: 113K+Points: 8
// Given a string str consisting of opening and closing parenthesis '(' and ')'. Find length of the longest valid parenthesis substring.

// A parenthesis string is valid if:

// For every opening parenthesis, there is a closing parenthesis.
// Opening parenthesis must be closed in the correct order.
// Examples :

// Input: str = ((()
// Output: 2
// Explaination: The longest valid parenthesis substring is "()".
// Input: str = )()())
// Output: 4
// Explaination: The longest valid parenthesis substring is "()()".
// Expected Time Complexity: O(|str|)
// Expected Auxiliary Space: O(|str|)

// Solution:

class Solution {
  public:
    int maxLength(string& s) {
        stack<int>st;
        int mx=0;
        int cnt=0;
        int pre=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==')' && !st.empty()){
                st.pop();
                if(!st.empty()){
                    int valid=i+1-st.top();
                    if(pre>st.top()){
                        valid=i+1-pre;
                    }
                    mx=max(valid,mx);
                }
                else   { 
                    mx=max(i+1-pre,mx);
                    
                }
                
                // cout<<mx<<" "<<i<<endl;
            }
            else if(s[i]==')' && st.empty()){
                pre=i+1;
            }
            else{
                st.push(i+1);
            }
        }
        return mx;
    }
};
