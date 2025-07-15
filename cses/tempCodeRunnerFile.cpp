#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int>&A,vector<int>&B,int a,int b,int pa,int pb,int n,int chance,vector<int>&sa,vector<int>&sb){
    if(chance==n){
        if(a==pa && b==pb){
            cout<<"YES"<<endl;
            for(auto i:sa){
                cout<<i<<" ";
            }
            cout<<endl;
            for(auto i:sb){
                cout<<i<<" ";
            }
            cout<<endl;
            return true;
        }
        return false;
    }
    for(int i=0;i<n;i++){
        if(A[i]==0){
            A[i]=1;
            int chA=i+1;
            sa.push_back(chA);
            for(int j=0;j<n;j++){
                if(B[j]==0){
                    int chB=j+1;
                    pa+=(chA>chB)?1:0;
                    pb+=(chA<chB)?1:0;
                    sb.push_back(chB);
                    B[j]=1;
                    if(solve(A,B,a,b,pa,pb,n,chance+1,sa,sb)){
                        return true;
                    }
                    sb.pop_back();
                    B[j]=0;
                }
            }
            A[i]=0;
            sa.pop_back();
        }
    }
}
void solve(int n,int a,int b){
    vector<int>A(n,0);
    vector<int>B(n,0);
    vector<int>sa;
    vector<int>sb;
    solve(A,B,a,b,0,0,n,0,sa,sb);
}
int main() {
    int t;
    cin>>t;
    while(t--){
        int n,a,b;
        cin>>n>>a>>b;
        
        solve(n,a,b);
    }
}