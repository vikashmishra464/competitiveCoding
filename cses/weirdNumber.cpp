#include<bits/stdc++.h>
using namespace std;
void solve(long long n){
    cout<<n<<" ";
    if(n==1){
        return;
    }
    n=(n%2==0)?n/2:(n*3)+1;
    return solve(n);
    
}
int main(){
    long long n;
    cin>>n;
    solve(n);
}