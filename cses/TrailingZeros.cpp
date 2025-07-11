#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void     solve(ll n){
    ll cnt=0;
    ll five=5;
    while(n/five!=0){
        cnt+=n/five;
        five*=5;
        // cout<<five<<endl;
    }
    cout<<cnt;

}

int main(){
    ll n;
    cin>>n;
    solve(n);
}