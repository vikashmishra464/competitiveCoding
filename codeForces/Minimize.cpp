//Question Link: https://codeforces.com/contest/2009/problem/A

// Question: 

// You are given two integers a
//  and b
//  (a≤b
// ). Over all possible integer values of c
//  (a≤c≤b
// ), find the minimum value of (c−a)+(b−c)
// .

// Input
// The first line contains t
//  (1≤t≤55
// ) — the number of test cases.

// Each test case contains two integers a
//  and b
//  (1≤a≤b≤10
// ).

// Output
// For each test case, output the minimum possible value of (c−a)+(b−c)
//  on a new line.

// Example
// Input
// 3
// 1 2
// 3 10
// 5 5
// Output
// 1
// 7
// 0

// Solution: 
// Time complexity -> O(t)

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        cout<<b-a<<endl;
    }
}
