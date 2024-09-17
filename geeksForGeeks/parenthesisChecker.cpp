// Question Link:https://www.geeksforgeeks.org/problems/parenthesis-checker2744/1
// Question:
// Parenthesis Checker
// Difficulty: EasyAccuracy: 28.56%Submissions: 581K+Points: 2
// Given an expression string x. Examine whether the pairs and the orders of {,},(,),[,] are correct in exp.
// For example, the function should return 'true' for exp = [()]{}{[()()]()} and 'false' for exp = [(]).

// Note: The driver code prints "balanced" if function return true, otherwise it prints "not balanced".

// Examples :

// Input: {([])}
// Output: true
// Explanation: { ( [ ] ) }. Same colored brackets can form balanced pairs, with 0 number of unbalanced bracket.
// Input: ()
// Output: true
// Explanation: (). Same bracket can form balanced pairs,and here only 1 type of bracket is present and in balanced way.
// Input: ([]
// Output: false
// Explanation: ([]. Here square bracket is balanced but the small bracket is not balanced and Hence , the output will be unbalanced.
// Expected Time Complexity: O(|x|)
// Expected Auixilliary Space: O(|x|)

// Constraints:
// 1 ≤ |x| ≤ 105

// Solution:
class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char>st;
        for(auto i:x){
            // cout<<i<<" "<<st.size()<<endl;
            if(i==')' || i=='}' || i==']'){
                if(st.empty()){
                    return false;
                }
                else{
                    if((i==')' && st.top()=='(')||(i=='}' && st.top()=='{')||(i==']' && st.top()=='[')){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
                
            }
            else if(i=='(' || i=='{' || i=='['){
                st.push(i);
            }
        }
        if(st.empty()){
            return true;
        }
        return false;
    }

};