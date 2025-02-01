#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
    int a1,a2,a4,a5;
    cin>>a1>>a2>>a4>>a5;
    int mx=1;
    int a3=a1+a2;
    int cnt=1;
    if(a4==a3+a2){
        cnt++;
    }
    if(a5==a4+a3){
        cnt++;
    }
    // cout<<cnt<<endl;
    mx=max(mx,cnt);
    a3=a4-a2;
    cnt=1;
    if(a5==a4+a3){
        cnt++;
    }
    // cout<<cnt<<endl;
    mx=max(mx,cnt);
    a3=a5-a4;
    cnt=1;
    if(a2==a3-a1){
        cnt++;
    }
    // cout<<cnt<<endl;
    mx=max(mx,cnt);
    cout<<mx<<endl;
    }
}