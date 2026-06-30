// class Solution
// {
// public:
//     int maxAreaOfIsland(vector<vector<int>> &grid)
//     {
//         int n = grid.size();
//         int m = grid[0].size();

//         vector<vector<int>> vis(n, vector<int>(m, 0));
//         queue<pair<int, int>> q;

//         int delRow[] = {1, 0, -1, 0};
//         int delCol[] = {0, 1, 0, -1};

//         int maxArea = 0;

//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < m; j++)
//             {
//                 if (grid[i][j] == 1 && vis[i][j] == 0)
//                 {

//                     q.push({i, j});
//                     vis[i][j] = 1;
//                     int area = 1;

//                     while (!q.empty())
//                     {
//                         int row = q.front().first;
//                         int col = q.front().second;
//                         q.pop();

//                         for (int k = 0; k < 4; k++)
//                         {
//                             int nrow = row + delRow[k];
//                             int ncol = col + delCol[k];

//                             if (nrow >= 0 && nrow < n &&
//                                 ncol >= 0 && ncol < m &&
//                                 grid[nrow][ncol] == 1 &&
//                                 vis[nrow][ncol] == 0)
//                             {

//                                 vis[nrow][ncol] = 1;
//                                 q.push({nrow, ncol});
//                                 area++;
//                             }
//                         }
//                     }
//                     maxArea = max(maxArea, area);
//                 }
//             }
//         }
//         return maxArea;
//     }
// };
