// Question Link: https://leetcode.com/problems/rotting-oranges/description/


// Question:
// You are given an m x n grid where each cell can have one of three values:

// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

// Example 1:


// Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
// Output: 4
// Example 2:

// Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
// Output: -1
// Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
// Example 3:

// Input: grid = [[0,2]]
// Output: 0
// Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 10
// grid[i][j] is 0, 1, or 2.

// Solution:

\
class Solution {
public:
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<pair<int, int>, int>> q; //({i,j},time)
        int visited[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    visited[i][j] = 2;
                }
                else{
                    visited[i][j]=0;
                }
            }
        }
        // BFS
        int maxtime = 0;
        while (!q.empty()) {
            int i = q.front().first.first;
            int j = q.front().first.second;
            int t = q.front().second;
            maxtime = max(t, maxtime);
            q.pop();
            for (int k = 0; k < 4; k++) {
                int new_i = i + dir[k][0];
                int new_j = j + dir[k][1];
                if (new_i >= 0 && new_i < m && new_j >= 0 && new_j < n &&
                    visited[new_i][new_j] != 2 && grid[new_i][new_j] != 0) {
                    q.push({{new_i, new_j}, t + 1});
                    visited[new_i][new_j] = 2;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] != 2 && grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return maxtime;
    }
};