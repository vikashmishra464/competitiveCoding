#include <bits/stdc++.h>
using namespace std;

long rearrangeStudents(vector<int>& arrA, vector<int>& arrB) {
    sort(arrA.begin(), arrA.end());
    sort(arrB.begin(), arrB.end());

    long totalCost = 0;
    int n = arrA.size();

    for (int i = 0; i < n; i++) {
        if (arrA[i] < arrB[i]) {
            return -1;
        }
        totalCost += arrB[i];
    }

    return totalCost;
}

int main() {
    vector<int> arrA = {1,2};
    vector<int> arrB = { 2,1};

    long result = rearrangeStudents(arrA, arrB);
    cout << result << endl;

    return 0;
}