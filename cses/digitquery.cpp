#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(ll n) {
    ll count=9;
    ll digit=1;
    ll start=1;
    while(n<=count*digit){
        n-=digit*count;
        count*=10;
        digit++;
        start*=10;
    }
    ll no=start+(n-1)/digit;
    
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        solve(n);
    }
}
