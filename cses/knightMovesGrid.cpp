#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>dir={{-2,-1},{-2,1},{-1,2},{1,2},{-1,-2},{1,-2},{2,-1},{2,1}};
void solve(int n){
    vector<vector<int>>arr(n,vector<int>(n,-1));
    arr[0][0]=0;
    queue<pair<pair<int,int>,int>>q;
    q.push({{0,0},0});
    while(!q.empty()){
        int row=q.front().first.first;
        int col=q.front().first.second;
        int cnt=q.front().second;
        q.pop();
        for(auto i:dir){
            int trow=row+i[0];
            int tcol=col+i[1];
            
            if(trow>=0 && trow<n && tcol>=0 && tcol<n && arr[trow][tcol]==-1){
                arr[trow][tcol]=cnt+1;
                q.push({{trow,tcol},cnt+1});
            }
        }
    }
    for(auto i:arr){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
int main() {
    int n;
    cin>>n;
    solve(n);
}