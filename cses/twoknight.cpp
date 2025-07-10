#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve(ll n) {
    long long totalmove=1LL*(n*n*((n*n)-1))/2;
    long long attackmove=1LL*4*(n-1)*(n-2);
    cout<<totalmove-attackmove<<endl;
}
 
int main() {
    ll n;
    cin>>n;
    for(int i=1;i<=n;i++){
        solve(i);
    }
    
}
