#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string n;
        cin>>n;
        string ans="";
        for(auto i:n){
            if(i=='p'){
                ans+='q';
            }
            else if(i=='q'){
                ans+='p';
            }
            else{
                ans+='w';
            }
        }
        reverse(ans.begin(),ans.end());
        cout<<ans<<endl;
    }
}