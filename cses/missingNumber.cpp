#include<bits/stdc++.h>
using namespace std;
void solve(int n,vector<int>&arr){
    for(auto i:arr){
        int idx=abs(i);
        arr[idx-1]*=-1;
    }
    int ans=n;
    for(int i=0;i<n-1;i++){
        if(arr[i]>0){
            ans=i+1;
        }
    }
    cout<<ans;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n-1);
    for(int i=0;i<n-1;i++){
        cin>>arr[i];
    }
    solve(n,arr);
}