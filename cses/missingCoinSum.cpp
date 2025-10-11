#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    long long missing=1;
    for(auto i:arr){
        if(missing>=i){
            missing+=i;
        }
        else{
            cout<<missing<<endl;
            return 0;
        }
    }
    cout<<missing<<endl;

}