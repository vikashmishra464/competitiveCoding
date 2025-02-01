// Question Link:https://codeforces.com/contest/2009/problem/D

// Question:
// Satyam is given n
//  distinct points on the 2D coordinate plane. It is guaranteed that 0≤yi≤1
//  for all given points (xi,yi)
// . How many different nondegenerate right triangles∗
//  can be formed from choosing three different points as its vertices?

// Two triangles a
//  and b
//  are different if there is a point v
//  such that v
//  is a vertex of a
//  but not a vertex of b
// .

// ∗
// A nondegenerate right triangle has positive area and an interior 90∘
//  angle.

// Input
// The first line contains an integer t
//  (1≤t≤104
// ) — the number of test cases.

// The first line of each test case contains an integer n
//  (3≤n≤2⋅105
// ) — the number of points.

// The following n
//  lines contain two integers xi
//  and yi
//  (0≤xi≤n
// , 0≤yi≤1
// ) — the i
// 'th point that Satyam can choose from. It is guaranteed that all (xi,yi)
//  are pairwise distinct.

// It is guaranteed that the sum of n
//  over all test cases does not exceed 2⋅105
// .

// Output
// Output an integer for each test case, the number of distinct nondegenerate right triangles that can be formed from choosing three points.

// Example
// InputCopy
// 3
// 5
// 1 0
// 1 1
// 3 0
// 5 0
// 2 1
// 3
// 0 0
// 1 0
// 3 0
// 9
// 1 0
// 2 0
// 3 0
// 4 0
// 5 0
// 2 1
// 7 1
// 8 1
// 9 1
// OutputCopy
// 4
// 0
// 8


// Solution:



#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        unordered_map<string,int>m;
        long long count=0;
        for(int i=0;i<n;i++){
            string x;
            cin>>x;
            string y;
            cin>>y;
            m[x+"_"+y]=1;
        }
        for(auto i:m){
            //case1:
            string k=i.first;
            string x="";
            string y="";
            bool u=false;
            for(int j=0;j<k.size();j++){
                if(k[j]=='_')u=true;
                if(u==false){
                    x+=k[j];
                }
                else if(k[j]!='_'){
                    y+=k[j];
                }
            }
            int a=stoi(x);
            int b=stoi(y);
            string start=to_string(a)+"_"+to_string(b);
            string start2;
            string end2;
            string end;
            if(b==0){
                end=to_string(a)+"_"+to_string(b+1);
                start2=to_string(a+1)+"_"+to_string(b+1);
                end2=to_string(a-1)+"_"+to_string(b+1);
 
            }
            else{
                end=to_string(a)+"_"+to_string(b-1);
                start2=to_string(a+1)+"_"+to_string(b-1);
                end2=to_string(a-1)+"_"+to_string(b-1);
            }
            if(m.find(end)!=m.end() && m[start]==1){
                m[end]=0;
                m[start]=0;
                count+=n-2;
            }
            //case2:
            if(m.find(start2)!=m.end() && m.find(end2)!=m.end()){
                count++;
            }
        }
        cout<<count<<endl;
    }
}