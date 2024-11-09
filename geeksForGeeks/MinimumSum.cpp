// Minimum sum
// Difficulty: MediumAccuracy: 17.14%Submissions: 128K+Points: 4
// Given an array arr[] such that each element is in the range [0 - 9], find the minimum possible sum of two numbers formed using the elements of the array. All digits in the given array must be used to form the two numbers. Return a string without leading zeroes.

// Examples :

// Input: arr[] = [6, 8, 4, 5, 2, 3]
// Output: 604
// Explanation: The minimum sum is formed by numbers 358 and 246.
// Input: arr[] = [5, 3, 0, 7, 4]
// Output: 82
// Explanation: The minimum sum is formed by numbers 35 and 047.
// Input: arr[] = [9, 4]
// Output: 13
// Explanation: The minimum sum is formed by numbers 9 and 4.
// Constraints:
// 1 ≤ arr.size() ≤ 106
// 0 ≤ arr[i] ≤ 9


// Solution:

class Solution {
  public:
    string str(string &f,string &s){
        // cout<<f<<"  "<<s<<endl;
        int i=f.size()-1;
        int j=s.size()-1;
        string ans="";
        int carry=0;
        while(i>=0 && j>=0){
            int first=f[i]-'0';
            int second=s[j]-'0';
            int r=first+second+carry;
            // cout<<first<<"  "<<second<<" "<<r<<endl;
            string res=to_string(r);
            if(res.size()==2){
                carry=res[0]-'0';
                ans+=res[1];
            }
            else{
                ans+=res[0];
                carry=0;
            }
            i--;
            j--;
        }
        while(i>=0){
            if(carry>0){
                int first=f[i]-'0';
                int r=first+carry;
                carry=0;
                string res=to_string(r);
                if(res.size()==2){
                    carry=res[0]-'0';
                    ans+=res[1];
                }
                else{
                    ans+=res[0];
                    carry=0;
                }
            }
            else{
                ans+=f[i];
            }
            
            i--;
        }
        while(j>=0){
            if(carry>0){
                int first=s[j]-'0';
                int r=first+carry;
                carry=0;
                string res=to_string(r);
                if(res.size()==2){
                    carry=res[0]-'0';
                    ans+=res[1];
                }
                else{
                    ans+=res[0];
                    carry=0;
                }
            }
            else{
                ans+=s[j];
            }
            
            j--;
        }
        if(carry>0){
            ans+=to_string(carry);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    string minSum(vector<int> &arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        string res="";
        string f="";
        int carry=0;
        for(int i=0;i<n;i+=2){
            f.push_back(arr[i]+'0');
        }
        string s="";
        for(int i=1;i<n;i+=2){
            s.push_back(arr[i]+'0');
        }
        string ans=str(f,s);
        string ans2="";
        bool t=true;
        for(auto i: ans){
            if(t && i=='0'){
                continue;
            }
            else{
                t=false;
                ans2+=i;
            }
        }
        return ans2;
        
        
    }
};