#include<bits/stdc++.h>
using namespace std;
using ll= long long;
int mod=1e9+7;
ll power(int no,ll time){
    if(time==0){
        return 1;
    }
    ll ans=(power(no,time/2))%mod;
    if(time%2!=0){
        return (1LL*ans*ans*no)%mod;
    }
    return (ans*ans)%mod;

}
void solve(ll n){
    ll ans=power(2,n);
    cout<<(ans)%mod;
}   
int main(){
    ll n;
    cin>>n;
    solve(n);
}