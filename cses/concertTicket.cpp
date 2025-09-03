#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;
    multiset<int>ticket;
    for(int i=0;i<n;i++){
        int p;
        cin>>p;
        ticket.insert(p);
    }
    for(int i=0;i<m;i++){
        int k;
        cin>>k;
        auto t=ticket.upper_bound(k);
        if(t!=ticket.begin()){
            t--;
            cout<<*t<<" ";
            ticket.erase(t);
        }
        else{
            cout<<-1<<" ";
        }
    }
    
}