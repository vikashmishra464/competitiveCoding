#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int m,a,b,c;
        cin>>m>>a>>b>>c;
        int rs=0;
        rs+=(m-a<=0)?0:m-a;
        rs+=(m-b<=0)?0:m-b;
        rs=(rs-c<=0)?0:rs-c;
        int totalseat=2*m;
        cout<<totalseat-rs<<endl;
    }
}