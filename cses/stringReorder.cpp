#include <bits/stdc++.h>
using namespace std;

void solve(string s){
    unordered_map<char,int>m;
    for(auto i:s){
        m[i]++;
    }

    priority_queue<pair<char,int>>p;
    for(auto i:m){
        p.push({i.first,i.second});
    }
    string k="";
    while(!p.empty()){
        pair<char,int>i=p.top();
        char k1=i.first;
        int f1=i.second;
        p.pop();
        k+=k1;
        if(!p.empty()){
            pair<char,int>j=p.top();
            char k2=j.first;
            int f2=j.second;
            p.pop();
            k+=k2;
            if(f2-1>0){
                p.push({k2,f2-1});
            }
            if(f2-1==0 && f1-1>0){
                k+=k1;
                f1--;
            }
        }
        if(f1-1>0 && p.empty()){
            cout<<-1<<endl;
            return;
        }
        if(f1-1>0){
            p.push({k1,f1-1});
        }
    }
    cout<<k<<endl;

}
int main() {
    string s;
    cin>>s;

}