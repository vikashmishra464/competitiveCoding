#include <bits/stdc++.h>
using namespace std;

void solve(string s) {
    int a = 0, c = 0, g = 0, t = 0;
    int ma = 0, mc = 0, mg = 0, mt = 0;

    for (char i : s) {
        if (i == 'A') {
            a++;
            c = g = t = 0;
        } else if (i == 'C') {
            c++;
            a = g = t = 0;
        } else if (i == 'G') {
            g++;
            a = c = t = 0;
        } else if (i == 'T') {
            t++;
            a = c = g = 0;
        }
        ma = max(ma, a);
        mc = max(mc, c);
        mg = max(mg, g);
        mt = max(mt, t);
    }

    cout << max({ma, mc, mg, mt}) << endl;
}

int main() {
    string s;
    cin >> s;
    solve(s);
}
