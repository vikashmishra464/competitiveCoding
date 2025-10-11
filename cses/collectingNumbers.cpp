#include <bits/stdc++.h>
using namespace std;
using t=pair<int,int>;
int main() {
    int n;
    cin>>n;
    priority_queue<t,vector<t>,greater<t>>pq;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        pq.push({x,i+1});
    }
    int time=0;
    int steps=1;
    while(!pq.empty()){
        t x=pq.top();
        pq.pop();
        if(time>x.second){
            steps++;
        }
        time=x.second;
    }
    cout<<steps;
}