#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    map<int,int>m;
    int ans=0;
    int j=0;
    for(int i=0;i<n;i++){
        m[arr[i]]++;
        while(m[arr[i]]>1){
            m[arr[j]]--;
            j++;
        }
        ans=max(ans,i-j+1);
    }
    cout<<ans;
}