// C++ recursive function to
// solve tower of hanoi puzzle
#include <bits/stdc++.h>
using namespace std;

void solve(int n,char A,char C,char B){
    if(n==0){
        return;
    }
    solve(n-1,A,B,C);
    cout<<A<<" "<<C<<endl;
    solve(n-1,B,C,A);
}
int main()
{
    int N;
    cin>>N;
    cout<<pow(2,N)-1<<endl;
    solve(N, '1', '3', '2');
    return 0;
}
