#include<bits/stdc++.h>
using namespace std;
int solve(const vector<int>& arr) {
    const auto n = arr.size();
    int sum = accumulate(arr.begin(), arr.end(), 0);
    priority_queue<int> pq;
    for (int i = 0; i < n / 2; i++) {
        pq.push(-arr[i]);
        pq.push(-arr[n - 1 - i]);
        cout<<-arr[i]<<"   "<<-arr[n-1-i]<<endl;
        sum += pq.top();
        cout<<sum<<"  ----  "<<pq.top()<<endl;
        pq.pop();
    }
    return sum;
}

int main() {
    cout<<solve({4, 4, 8, 5, 3, 2}); // 17

    cout<<"------->"<<endl;
    cout<<solve({1,5,3,5,1}); // 13

    cout<<"------->"<<endl;
    cout<<solve({1,5,1,5,5,1}); // 15

    cout<<"------->"<<endl;
    cout<<solve({4,8,3,2,5}); // 16

    cout<<"------->"<<endl;
    cout<<solve({9, 24, 4, 37, 42, 26, 12, 44, 14, 11, 36, 42, 50, 47, 39, 5, 19, 47, 7, 6, 26, 24, 11, 44, 8, 33, 18, 36, 5, 46});
}