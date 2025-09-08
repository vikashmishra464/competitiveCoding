#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long x;
    cin >> n >> x;
    vector<pair<long long, int>> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
        arr[i].second = i + 1; // store original 1-based index
    }

    sort(arr.begin(), arr.end());

    int l = 0, r = n - 1;
    while (l < r) {
        long long sum = arr[l].first + arr[r].first;
        if (sum == x) {
            cout << arr[l].second << " " << arr[r].second;
            return 0;
        }
        if (sum < x) l++;
        else r--;
    }

    cout << "IMPOSSIBLE";
    return 0;
}
