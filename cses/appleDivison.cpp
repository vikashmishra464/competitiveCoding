#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll mn = LLONG_MAX;  // Use LLONG_MAX for long long

void solve(vector<int>&arr,ll f,ll s,int idx) {
    if(idx>=arr.size()){
        mn=min(abs(f-s),mn);
        return ;
    }
    solve(arr,f+arr[idx],s,idx+1);
    solve(arr,f,s+arr[idx],idx+1);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }  
    solve(arr,0,0,0);
    cout<<mn;

    return 0;
}
