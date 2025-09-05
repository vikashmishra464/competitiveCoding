#include <bits/stdc++.h>
using namespace std;
int mod=1e9+7;
long long solve(long long n,long long sum,vector<long long>&dp){
    if(sum==n){
        return 1;
    }
    if(sum>n){
        return 0;
    }
    if(dp[sum]!=-1){
        return (dp[sum])%mod;
    }
    long long total=0;
    for(int i=1;i<=6;i++) 
        if(sum+i<=n) total+=solve(n,sum+i,dp);
    return dp[sum]=(total)%mod;
}
int main() {
    long long n;
    cin>>n;
    vector<long long>dp(n+1,-1);
    cout<<(solve(n,0,dp))%mod;
}