#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    multiset<int>m;
    for(auto i:arr){
        auto upperbound=m.upper_bound(i);
        
        if(upperbound!=m.end()){
            // cout<<i<<" "<<*upperbound<<" "<<m.size()<<endl;
            m.erase(upperbound);
        }
        m.insert(i);
    }
    cout<<m.size()<<endl;
}