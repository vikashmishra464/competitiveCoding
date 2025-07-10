#include<bits/stdc++.h>
using namespace std;
void solve(int n){
    if(n==3 || n==2){
        cout<<"NO SOLUTION";
    }
    else{
        for(int i=2;i<=n;i+=2){
            cout<<i<<" ";
        }
        for(int i=1;i<=n;i+=2){
            cout<<i<<" ";
        }
    }
}
int main(){
    int n;
    cin>>n;
    solve(n);
}