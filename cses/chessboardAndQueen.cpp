#include <bits/stdc++.h>
using namespace std;

bool check(vector<string>&arr,int row,int col){
    for(int i=0;i<=row;i++){
        if(arr[i][col]=='Q'){
            return false;
        }
    }
    int temprow=row;
    int tempcol=col;
    while(temprow>=0 && tempcol>=0){
        if(arr[temprow][tempcol]=='Q'){
            return false;
        }
        temprow-=1;
        tempcol-=1;
    }
    temprow=row;
    tempcol=col;
    while(temprow>=0 && tempcol<8){
        if(arr[temprow][tempcol]=='Q'){
            return false;
        }
        temprow-=1;
        tempcol+=1;
    }
    return true;
}
int solve(vector<string>&arr,int row){
    if(row>=8){
        return 1;
    }
    string &k=arr[row];
    int ans=0;
    for(int i=0;i<8;i++){
        if(k[i]=='*'){
            continue;
        }
        if(check(arr,row,i)){
            k[i]='Q';
            ans+=solve(arr,row+1);
            k[i]='.';
        }
    }
    return ans;
}
int main() {
    vector<string>arr;
    for(int i=0;i<8;i++){
        string k;
        cin>>k;
        arr.push_back(k);
    }
    cout<<solve(arr,0);
}