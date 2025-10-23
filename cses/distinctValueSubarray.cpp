#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    long long ans=0;
    int i=0;
    unordered_map<int,int>m;
    for(int j=0;j<n;j++){
        m[arr[j]]++;
        while(m[arr[j]]>1){
            m[arr[i]]--;
            i++;
        }
        // cout<<i<<" "<<j<<endl;
        ans+=j-i+1;
    }
    cout<<ans<<endl;
}