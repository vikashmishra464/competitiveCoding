#include <bits/stdc++.h>
using namespace std;

void solve(int n,int k,vector<long long>&arr){
    int l=0;
    int r=n-1;
    long long cnt=0;
    sort(arr.begin(),arr.end());
    while(l<=r){
        if(arr[l]+arr[r]<=k){
            cnt++;
            l++;
            r--;
        }
        else{
            r--;
            cnt++;
        }
    }
    cout<<cnt<<endl;
}

int main() {
    int n,k;
    vector<long long>arr;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    solve(n,k,arr);
}