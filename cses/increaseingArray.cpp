#include<bits/stdc++.h>
using namespace std;
void solve(int n,vector<int>&arr){
    long long added=0;
    for(int i=1;i<n;i++){
        if(arr[i]>=arr[i-1]){
            continue;
        }
        added+=abs(arr[i]-arr[i-1]);
        arr[i]=arr[i-1];
    }
    cout<<added;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    solve(n,arr);
}