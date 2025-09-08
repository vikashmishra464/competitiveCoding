#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    long long sum=0;
    long long ans=arr[0];
    for(int i=0;i<n;i++){
        sum+=arr[i];
        ans=max(ans,sum);
        if(sum<0){
            sum=0;
        }
    }
    cout<<ans;
}