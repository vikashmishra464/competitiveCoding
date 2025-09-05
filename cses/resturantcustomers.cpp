#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<vector<int>>arr;
    for(int i=0;i<n;i++){
        int start,end;
        cin>>start>>end;
        arr.push_back({start,+1});
        arr.push_back({end,-1});
    }
    sort(arr.begin(),arr.end());
    int cnt=0;
    int ans=0;
    for(auto i:arr){
        cnt+=i[1];
        ans=max(cnt,ans);
    }
    cout<<ans;
}