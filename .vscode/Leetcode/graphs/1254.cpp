// class Solution
// {
// private:
//     bool check(vector<vector<int>> &grid, queue<pair<int, int>> &q, int n, int m)
//     {

//         while (!q.empty())
//         {
//             int r = q.front().first;
//             int c = q.front().second;
//             q.pop();

//             if (r == 0 || c == 0 || r == n - 1 || c == m - 1)
//             {
//                 return false;
//             }
//         }
//         return true;
//     }
//     void dfs(int r, int c, vector<vector<int>> &grid, vector<vector<int>> &vis, queue<pair<int, int>> &q, int n, int m)
//     {
//         vis[r][c] = 1;
//         q.push({r, c});

//         int delRow[] = {1, 0, -1, 0};
//         int delCol[] = {0, -1, 0, 1};

//         for (int i = 0; i < 4; i++)
//         {
//             int nrow = r + delRow[i];
//             int ncol = c + delCol[i];

//             if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 0)
//             {
//                 dfs(nrow, ncol, grid, vis, q, n, m);
//             }
//         }
//     }

// public:
//     int closedIsland(vector<vector<int>> &grid)
//     {
//         int n = grid.size();
//         int m = grid[0].size();
//         vector<vector<int>> vis(n, vector<int>(m, 0));
//         int cnt = 0;
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < m; j++)
//             {
//                 if (!vis[i][j] && !grid[i][j])
//                 {
//                     queue<pair<int, int>> q;
//                     dfs(i, j, grid, vis, q, n, m);
//                     if (check(grid, q, n, m))
//                     {
//                         cnt++;
//                     }
//                 }
//             }
//         }
//         return cnt;
//     }
// };