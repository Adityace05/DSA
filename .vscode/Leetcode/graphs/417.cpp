// class Solution
// {
// private:
//     void dfs(int r, int c, vector<vector<int>> &P,
//              vector<vector<int>> &heights, int m, int n)
//     {

//         int delRow[] = {1, 0, -1, 0};
//         int delCol[] = {0, -1, 0, 1};

//         for (int i = 0; i < 4; i++)
//         {
//             int nrow = r + delRow[i];
//             int ncol = c + delCol[i];

//             if (nrow >= 0 && ncol >= 0 && nrow < m && ncol < n && !P[nrow][ncol])
//             {
//                 if (heights[nrow][ncol] >= heights[r][c])
//                 {
//                     P[nrow][ncol] = 1;
//                     dfs(nrow, ncol, P, heights, m, n);
//                 }
//             }
//         }
//     }

// public:
//     vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
//     {
//         int m = heights.size();
//         int n = heights[0].size();

//         vector<vector<int>> P(m, vector<int>(n, 0));
//         vector<vector<int>> A(m, vector<int>(n, 0));
//         vector<vector<int>> ans;

//         for (int i = 0; i < m; i++)
//         {
//             P[i][0] = 1;
//             dfs(i, 0, P, heights, m, n);
//         }
//         for (int j = 0; j < n; j++)
//         {
//             P[0][j] = 1;
//             dfs(0, j, P, heights, m, n);
//         }

//         for (int i = 0; i < m; i++)
//         {
//             A[i][n - 1] = 1;
//             dfs(i, n - 1, A, heights, m, n);
//         }
//         for (int j = 0; j < n; j++)
//         {
//             A[m - 1][j] = 1;
//             dfs(m - 1, j, A, heights, m, n);
//         }

//         for (int i = 0; i < m; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 if (P[i][j] && A[i][j])
//                 {
//                     ans.push_back({i, j});
//                 }
//             }
//         }
//         return ans;
//     }
// };
