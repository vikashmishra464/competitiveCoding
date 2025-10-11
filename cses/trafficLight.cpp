#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int x, n;
    cin >> x >> n;

    set<int> lights;                   // traffic light positions
    multiset<int> gaps;                // segment lengths (ascending, largest = rbegin())
    
    lights.insert(0);
    lights.insert(x);
    gaps.insert(x);                    // initial full segment

    while (n--) {
        int k;
        cin >> k;

        // Find neighbors
        auto right = lights.upper_bound(k);
        auto left = prev(right);

        // Remove old segment
        gaps.erase(gaps.find(*right - *left));

        // Insert new light
        lights.insert(k);

        // Insert new segments
        gaps.insert(k - *left);
        gaps.insert(*right - k);

        // Print largest segment
        cout << *gaps.rbegin() << " ";
    }
}
