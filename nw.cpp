#include<bits/stdc++.h>
using namespace std;

int solve(int n, vector<int>& dp) {
    if (n <= 1) {
        return n;
    }

    if (dp[n] != -1) { 
        return dp[n];
    }
    return solve(n - 1, dp) + solve(n - 2, dp);
}

int main() {
    int n;
    cin >> n;

    vector<int> dp(n + 1, -1); 
    int result = solve(n, dp);

    cout << result << endl;
    return 0;
}
