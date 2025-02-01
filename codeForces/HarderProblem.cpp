#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    unordered_map<int, int> freq;        // Tracks frequency of each number in `b`
    unordered_map<int, int> freq_count;  // Tracks how many numbers have a specific frequency
    vector<int> b(n);                    // Result array
    int mode = a[0], max_freq = 0;       // Track the mode and max frequency

    for (int i = 0; i < n; i++) {
        int num = a[i];
        int prev_freq = freq[num];  // Get previous frequency

        // Update frequency map
        freq[num]++;
        int new_freq = freq[num];   // Get new frequency

        // Update frequency count tracking
        freq_count[prev_freq]--;
        freq_count[new_freq]++;

        // Update mode dynamically
        if (new_freq > max_freq) {
            max_freq = new_freq;
            mode = num;
        } else if (new_freq == max_freq && freq_count[max_freq] == 1) {
            mode = num;
        }

        b[i] = mode;  // Store mode in `b`
    }

    // Print the result efficiently
    for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
    cout << "\n";
}
}