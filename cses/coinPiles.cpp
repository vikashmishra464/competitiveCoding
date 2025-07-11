#include <bits/stdc++.h>
using namespace std;


using ll=long long;

void solve(ll a,ll b){
    if(b<a){
        return solve(b,a);
    }
    if(a==0 && b==0){
        cout<<"YES"<<endl;
    }
    else if(a==0 || b==0){
        cout<<"NO"<<endl;
    }
    else if((b+a)%3==0 && a*2>=b){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}
int main() {
    int n;
    cin>>n;
    while(n--){
        ll a,b;
        cin>>a>>b;
        solve(a,b);
    }
}
