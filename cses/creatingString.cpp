#include <bits/stdc++.h>
using namespace std;
vector<string>ans;
void solve(vector<int>&arr,int n,string &output){
    if(output.size()==n){
        ans.push_back(output);
        return;
    }
    for(int i=0;i<26;i++){
        if(arr[i]>0){
            output.push_back('a'+i);
            arr[i]--;
            solve(arr,n,output);
            arr[i]++;
            output.pop_back();
        }
    }
}
int main() {
    string s;
    cin>>s;
    int n=s.size();
    vector<int>arr(26,0);
    for(auto i:s){
        arr[i-'a']++;
    }
    string output="";
    solve(arr,n,output);
    cout<<ans.size()<<endl;
    for(auto i:ans){
        cout<<i<<endl;
    }
}
