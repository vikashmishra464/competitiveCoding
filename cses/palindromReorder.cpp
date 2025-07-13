#include <bits/stdc++.h>
using namespace std;

void solve(string s){
    vector<int>arr(26,0);
    for(auto i:s){
        arr[i-'A']++;
    }
    string f="";
    string se="";
    string mid="";
    for(int i=0;i<26;i++){
        char ch='A'+i;
        if(arr[i]%2==0){
            int cnt=arr[i]/2;
            for(int j=0;j<cnt;j++){
                f+=ch;
                se+=ch;
            }
        }
        else{
            if(mid.size()==0){
                for(int j=0;j<arr[i];j++){
                    mid+=ch;
                }
            }
            else{
                cout<<"NO SOLUTION";
                return;
            }
        }
    }
    reverse(se.begin(),se.end());
    cout<<f+mid+se;
}
int main() {
    string s;
    cin>>s;
    solve(s);
}