#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin>>s;
    vector<int>arr(26,0);
    for(auto i:s){
        arr[i-'A']++;
    }
    int n=s.size();
    for(auto i:arr){
        if(n%2==0 && i>n/2){
            cout<<-1<<endl;
            return 0;
        }
        else if(n%2!=0 && i>(n/2)+1){
            cout<<-1<<endl;
            return 0;
        }
    }
    string ans="";
    while(ans.size()<s.size()){
        // cout<<ans<<endl;
        int mf=0;
        char ch;
        for(int i=0;i<26;i++){
            if(mf<arr[i]){
                mf=arr[i];
                ch='A'+i;
            }
        }
        // cout<<mf<<" "<<n-ans.size()-mf<<" "<<ch<<endl;
        if(mf-1==n-ans.size()-mf){
            while(mf--){
                ans+=ch;
                arr[ch-'A']--;
                for(int j=0;j<26;j++){
                    char cur='A'+j;
                    if(ans.back()!=cur && arr[j]>0){
                        ans+=cur;
                        arr[j]--;
                        break;
                    }
                }
            }
        }
        else{
            for(int j=0;j<26;j++){
                char cur='A'+j;
                if(ans.back()!=cur && arr[j]>0){
                    ans+=cur;
                    arr[j]--;
                    break;
                }
            }
        }
    }
    cout<<ans;

}
