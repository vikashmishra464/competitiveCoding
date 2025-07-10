#include<bits/stdc++.h>
using namespace std;
void solve(long long row,long long col){
    if(row>=col){
        if(row%2==0){
            cout<<row*row +1 +col<<endl;
        }
        else{
            cout<<((row+1)*(row+1)) -col<<endl;
        }
    }
    else{
        if(col%2==0){
            cout<<(col+1)*(col+1) -row<<endl;
        }
        else{
            cout<<(col*col)+1+row<<endl;
        }
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        long long row,col;
        cin>>row>>col;
        solve(row-1,col-1);
    }
}