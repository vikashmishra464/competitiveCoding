#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> arr(7, vector<int>(7, 0));

int solve(int row, int col, int idx, string& pat) {
    if (row == 6 && col == 0) {
        return idx == 48 ? 1 : 0;
    }
    if (row < 0 || col < 0 || row > 6 || col > 6 || idx >= 48 || arr[row][col] == 1) {
        return 0;
    }

    arr[row][col] = 1;
    int ans = 0;

    if (pat[idx] == 'U' || pat[idx] == '?') {
        ans += solve(row - 1, col, idx + 1, pat);
    }
    if (pat[idx] == 'D' || pat[idx] == '?') {
        ans += solve(row + 1, col, idx + 1, pat);
    }
    if (pat[idx] == 'L' || pat[idx] == '?') {
        ans += solve(row, col - 1, idx + 1, pat);
    }
    if (pat[idx] == 'R' || pat[idx] == '?') {
        ans += solve(row, col + 1, idx + 1, pat);
    }

    arr[row][col] = 0;
    return ans;
}

int main() {
    string s;
    cin >> s;
    cout << solve(0, 0, 0, s) << endl;
    return 0;
}
