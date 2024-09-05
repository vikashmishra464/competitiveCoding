// Question Link:https://codeforces.com/contest/2009/problem/C

// Question:
// Freya the Frog is traveling on the 2D coordinate plane. She is currently at point (0,0)
//  and wants to go to point (x,y)
// . In one move, she chooses an integer d
//  such that 0≤d≤k
//  and jumps d
//  spots forward in the direction she is facing.

// Initially, she is facing the positive x
//  direction. After every move, she will alternate between facing the positive x
//  direction and the positive y
//  direction (i.e., she will face the positive y
//  direction on her second move, the positive x
//  direction on her third move, and so on).

// What is the minimum amount of moves she must perform to land on point (x,y)
// ?

// Input
// The first line contains an integer t
//  (1≤t≤104
// ) — the number of test cases.

// Each test case contains three integers x
// , y
// , and k
//  (0≤x,y≤109,1≤k≤109
// ).

// Output
// For each test case, output the number of jumps Freya needs to make on a new line.

// Example
// InputCopy
// 3
// 9 11 3
// 0 10 8
// 1000000 100000 10
// OutputCopy
// 8
// 4
// 199999
// Note
// In the first sample, one optimal set of moves is if Freya jumps in the following way: 
//  (0,0) →
//  (2,0) →
//  (2,2) →
//  (3,2) →
//  (3,5) →
//  (6,5) →
//  (6,8) →
//  (9,8) →
//  (9,11). This takes 8 jumps.

// Solution :
// Time complexity: O(1)
// Space complexity: O(1)

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y, k;
        cin >> x >> y >> k;
        int step = 0;
        if (x == 0 && y == 0)
        {
            step = 0;
        }
        else
        {
            if (k >= x && k >= y)
            {
                if (y == 0)
                {
                    step = 1;
                }
                else
                {
                    step = 2;
                }
            }
            else if (x == y)
            {
                step = x / k;
                step += (x % k == 0) ? 0 : 1;
                step = step * 2;
            }
            else if(x > y && x > k && ceil(x/(double)k)==ceil(y/(double)k)){
                step = x / k;
                step += (x % k == 0) ? 0 : 1;
                step = step * 2;
            }
            else if (x > y && x > k)
            {
                step = x / k;
                step += (x % k == 0) ? 0 : 1;
                step = step * 2;
                step--;
            }
            else if (y > x && y > k)
            {
                step = y / k;
                step += (y % k == 0) ? 0 : 1;
                step = step * 2;
            }
        }
        cout << step << endl;
    }
}