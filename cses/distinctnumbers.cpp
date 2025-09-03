#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    unordered_set<int>m;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        m.insert(val);
    }
    cout<<m.size();
}
