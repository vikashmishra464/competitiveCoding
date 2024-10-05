// Find the number of islands
// Difficulty: MediumAccuracy: 42.12%Submissions: 196K+Points: 4
// Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of '0's (Water) and '1's(Land). Find the number of islands.

// Note: An island is either surrounded by water or the boundary of a grid and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.

// Examples:

// Input: grid = [[0,1],[1,0],[1,1],[1,0]]
// Output: 1
// Explanation:
// The grid is-
// 0 1
// 1 0
// 1 1
// 1 0
// All lands are connected.
// Input: grid = [[0,1,1,1,0,0,0],[0,0,1,1,0,1,0]]
// Output: 2
// Expanation:
// The grid is-
// 0 1 1 1 0 0 0
// 0 0 1 1 0 2 0 
// There are two islands in the grid. One island is marked by '1' and the other by '2'.
// Expected Time Complexity: O(n*m)
// Expected Space Complexity: O(n*m)

// Constraints:
// 1 ≤ n, m ≤ 500
// 0 ≤ grid[i][j] ≤ 1Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of '0's (Water) and '1's(Land). Find the number of islands.


// Note: An island is either surrounded by water or the boundary of a grid and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.

// Examples:

// Input: grid = [[0,1],[1,0],[1,1],[1,0]]
// Output: 1
// Explanation:
// The grid is-
// 0 1
// 1 0
// 1 1
// 1 0
// All lands are connected.
// Input: grid = [[0,1,1,1,0,0,0],[0,0,1,1,0,1,0]]
// Output: 2
// Expanation:
// The grid is-
// 0 1 1 1 0 0 0
// 0 0 1 1 0 2 0 
// There are two islands in the grid. One island is marked by '1' and the other by '2'.
// Expected Time Complexity: O(n*m)
// Expected Space Complexity: O(n*m)

// Constraints:
// 1 ≤ n, m ≤ 500
// grid[i][j] = {'0', '1'}


// Solution:
class Solution {
  public:
    int dir[8][2]={{1,0},{-1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,1},{1,-1}};
    void BFS(vector<vector<char>>& grid,int i,int j){
        int  n=grid.size();
        int  m=grid[0].size();
        queue<pair<int,int>>q;
        q.push({i,j});
        grid[i][j]='0';
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<8;i++){
                int fx=x+dir[i][0];
                int fy=y+dir[i][1];
                if(fx>=0 && fx<n && fy>=0 && fy<m && grid[fx][fy]=='1'){
                    grid[fx][fy]='0';
                    q.push({fx,fy});
                }
            }
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int  n=grid.size();
        int  m=grid[0].size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    BFS(grid,i,j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
