#include <bits/stdc++.h>
using namespace std;

unordered_map<char, vector<int>> m;
vector<vector<int>> arr;

int solve(string &s, int idx, int row, int col) {
    if (idx == (int)s.size() && row == 6 && col == 6) {
        return 1;
    }
    if (idx == (int)s.size()) return 0;

    arr[row][col] = 1;
    int ans = 0;

    if (s[idx] == '?') {
        for (auto &p : m) {
            int trow = row + p.second[0];
            int tcol = col + p.second[1];
            if (trow >= 0 && trow < 7 && tcol >= 0 && tcol < 7 && arr[trow][tcol] == 0) {
                ans += solve(s, idx + 1, trow, tcol);
            }
        }
    } else {
        int trow = row + m[s[idx]][0];
        int tcol = col + m[s[idx]][1];
        if (trow >= 0 && trow < 7 && tcol >= 0 && tcol < 7 && arr[trow][tcol] == 0) {
            ans += solve(s, idx + 1, trow, tcol);
        }
    }

    arr[row][col] = 0; // backtrack
    return ans;
}

int main() {
    string s;
    cin >> s;

    m['U'] = {-1, 0};
    m['D'] = {1, 0};
    m['L'] = {0, -1};
    m['R'] = {0, 1};

    arr.resize(7, vector<int>(7, 0));
    cout << solve(s, 0, 0, 0) << "\n";
}
