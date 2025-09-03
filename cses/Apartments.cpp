#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>>arr;
    for(int i=0;i<n;i++){
        int room;
        cin>>room;
        arr.push_back({room-k,room+k});
    }
    sort(arr.begin(),arr.end());
    vector<int>ap;
    for(int i=0;i<m;i++){   
        int room;
        cin>>room;
        ap.push_back(room);
    }
    sort(arr.begin(),arr.end());
    sort(ap.begin(),ap.end());
    int idx=0;
    int cnt=0;
    
    for(int i=0;i<m && idx<n ;i++){
        
        while(idx<n && arr[idx][1]<ap[i] ){
            idx++;
        }
        if(idx<n && arr[idx][0]<=ap[i] && arr[idx][1]>=ap[i]){
            cnt++;
            idx++;
        }
    }
    cout<<cnt<<endl;
}