#include <bits/stdc++.h>
using namespace std;

void solve(int n){
    for (int i = 0; i <pow(2,n); i++) {
        int grey=(i^(i>>1));
        string k="";
        int f=n;
        while(f--){
            k+=to_string(grey&1);
            grey=grey>>1;
        }

        reverse(k.begin(),k.end());
        cout<<k<<endl;
    }
}

int main() {
    int n;
    cin >> n;
    solve(n);
}
