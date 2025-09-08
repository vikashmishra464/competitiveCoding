#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<vector<int>>arr;
    for(int i=0;i<n;i++){
        int start,end;
        cin>>start>>end;
        arr.push_back({start,end});
    }
    sort(arr.begin(),arr.end());
    int cnt=1;
    int start=arr[0][0];
    int end=arr[0][1];

    for(int i=1;i<n;i++){
        int tstart=arr[i][0];
        int tend=arr[i][1];
        if((start<=tstart && tstart<end)||(start<=tend && tend<=end)){
                end=min(end,tend);
        }
        else{
            cnt++;
            end=tend;
        }
    }
    cout<<cnt<<endl;
}