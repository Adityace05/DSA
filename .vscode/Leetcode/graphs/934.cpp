// class Solution
// {
// private:
//     void dfs(int r, int c, vector<vector<int>> &grid, vector<vector<int>> &vis, vector<vector<pair<int, int>>> &com, int k, int n)
//     {
//         vis[r][c] = 1;
//         com[k].push_back({r, c});

//         int delRow[] = {1, 0, -1, 0};
//         int delCol[] = {0, -1, 0, 1};

//         for (int i = 0; i < 4; i++)
//         {
//             int nrow = r + delRow[i];
//             int ncol = c + delCol[i];
//             if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && grid[nrow][ncol] && !vis[nrow][ncol])
//             {
//                 dfs(nrow, ncol, grid, vis, com, k, n);
//             }
//         }
//     }

// public:
//     int shortestBridge(vector<vector<int>> &grid)
//     {
//         int n = grid.size();
//         vector<vector<pair<int, int>>> com;
//         vector<vector<int>> vis(n, vector<int>(n, 0));

//         int k = 0;
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 if (!vis[i][j] && grid[i][j] == 1)
//                 {
//                     com.push_back({});
//                     dfs(i, j, grid, vis, com, k, n);
//                     k++;
//                 }
//             }
//         }

//         int ans = INT_MAX;
//         for (auto &p1 : com[0])
//         {
//             for (auto &p2 : com[1])
//             {
//                 int dist = abs(p1.first - p2.first) + abs(p1.second - p2.second) - 1;
//                 ans = min(ans, dist);
//             }
//         }
//         return ans;
//     }
// };