#include <bits/stdc++.h>
using namespace std;
 
void solve(int n,int a,int b){
    if(n<a+b){
        cout<<"NO"<<endl;
        return;
    }
    else if((a!=0 && b==0 )|| (b!=0 && a==0)){
        cout<<"NO"<<endl;
        return;
    }
    vector<int>A(n);
    vector<int>B(n);
    for(int i=0;i<n;i++){
        A[i]=i+1;
    }
    int idx=n-1;
    int rem=n-a-b;
    for(int i=0;i<rem;i++){
        B[n-i-1]=n-i;
    }
 
    int start=n-rem-b+1;
    idx=0;
 
    for(int i=0;i<b;i++){
        B[idx]=start++;
        idx++;
    }
    for(int i=0;i<a;i++){
        B[idx]=i+1;
        idx++;
    }
    cout<<"YES"<<endl;
    for(auto i:A){
        cout<<i<<" ";
    }
    cout<<endl;
    for(auto i:B){
        cout<<i<<" ";
    }
    cout<<endl;
}
int main() {
    int t;
    cin>>t;
    while(t--){
        int n,a,b;
        cin>>n>>a>>b;
        solve(n,a,b);
    }
}
