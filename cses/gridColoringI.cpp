#include <bits/stdc++.h>
using namespace std;

void solve(vector<string>&arr,int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(auto k:{'A','B','C','D'}){
                char up=(i-1>=0)?arr[i-1][j]:'1';
                char left=(j-1>=0)?arr[i][j-1]:'1';
                char cur=arr[i][j];
                
                if(k!=up && k!=left && k!=cur){
                    // cout<<i<<" "<<j<<" "<<cur<<" "<<k<<endl;
                    arr[i][j]=k;
                    break;
                }
            }
        }
    }
    for(auto i:arr){
        cout<<i<<endl;
    }
}
int main() {
    int n,m;
    cin>>n>>m;
    vector<string>arr;
    for(int i=0;i<n;i++){
        string k;
        cin>>k;
        arr.push_back(k);
    }
    solve(arr,n,m);
}