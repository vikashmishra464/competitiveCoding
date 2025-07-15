#include <bits/stdc++.h>
using namespace std;

bool check(vector<vector<int>>&arr,int row,int col,int val){
    for(int i=0;i<row;i++){
        if(arr[i][col]==val){
            return false;
        }
    }
    for(int i=0;i<col;i++){
        if(arr[row][i]==val){
            return false;
        }
    }
    return true;
}
void solve(int n){
    vector<vector<int>>arr(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            int f=false;
            int k=0;
            while(!check(arr,i,j,k)){
                k++;
            }
            arr[i][j]=k;
            arr[j][i]=k;
        }
    }
    for(auto i:arr){
        for(auto j:i){
            cout<<j<<" "; 
        }
        cout<<endl;
    }

}
int main() {
    int n;
    cin>>n;
    solve(n);
}