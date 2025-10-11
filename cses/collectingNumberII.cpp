#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    vector<int> pos(n + 1);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        pos[arr[i]] = i;
    }

    auto contrib = [&](int x) {
        if (x >= 1 && x < n) {
            return (pos[x + 1] < pos[x]) ? 1 : 0;
        }
        return 0;
    };

    int rounds = 1;
    for (int i = 1; i < n; i++) {
        rounds += contrib(i);
    }

    while (m--) {
        int a, b;
        cin >> a >> b;
        --a; --b;

        int u = arr[a], v = arr[b];

        // remove old contributions
        for (int x : {u - 1, u, v - 1, v}) {
            if (x >= 1 && x < n) rounds -= contrib(x);
        }

        // swap in arr and pos
        swap(arr[a], arr[b]);
        swap(pos[u], pos[v]);

        // add new contributions
        for (int x : {u - 1, u, v - 1, v}) {
            if (x >= 1 && x < n) rounds += contrib(x);
        }

        cout << rounds << "\n";
    }

    return 0;
}
