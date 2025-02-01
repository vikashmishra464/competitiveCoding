// Question Link: https://codeforces.com/contest/2009/problem/B

// Question:
// You are playing your favorite rhythm game, osu!mania. The layout of your beatmap consists of n
//  rows and 4
//  columns. Because notes at the bottom are closer, you will process the bottommost row first and the topmost row last. Each row will contain exactly one note, represented as a '#'.

// For each note 1,2,…,n
// , in the order of processing, output the column in which the note appears.

// Input
// The first line contains t
//  (1≤t≤100
// ) — the number of test cases.

// For each test case, the first line contains n
//  (1≤n≤500
// ) — the number of rows of the beatmap.

// The following n
//  lines contain 4
//  characters. The i
// -th line represents the i
// -th row of the beatmap from the top. It is guaranteed that the characters are either '.' or '#', and exactly one of the characters is '#'.

// It is guaranteed that the sum of n
//  over all test cases does not exceed 500
// .

// Output
// For each test case, output n
//  integers on a new line, the column that the i
// -th note appears in for all i
//  from 1
//  to n
// .

// Example
// Input
// 3
// 4
// #...
// .#..
// ..#.
// ...#
// 2
// .#..
// .#..
// 1
// ...#

// Output
// 4 3 2 1 
// 2 2 
// 4 

//Solution:
// Time complexity -> O(t*n)

#include<bits/stdc++.h>
using namespace std;
void solve(int n){
    if(n==0){
        return;
    }
    string s;
    cin>>s;
    solve(n-1);
    for(int i=0;i<4;i++){
        if(s[i]=='#'){
            cout<<i+1;
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        solve(n);
        cout<<endl;
        }
    }
