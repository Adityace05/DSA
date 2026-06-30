// #include <iostream>
// #include <vector>
// #include <queue>
// #include <map>

// using namespace std;

// void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> & not, int delrow[], int delcol[])
// {
//     int n = not.size();
//     int m = not[0].size();

//     for (int i = 0; i < 4; i++)
//     {
//         int nrow = row + delrow[i];
//         int ncol = col + delcol[i];

//         if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && !vis[nrow][ncol] && not[nrow][ncol] == 'O')
//         {
//             vis[nrow][ncol] = 1;
//             dfs(nrow, ncol, vis, not, delrow, delcol);
//         }
//     }
// }

// vector<vector<char>> fill(int n, int m, vector<vector<char>> not)
// {
//     vector<vector<int>> vis(n, vector<int>(m, 0));
//     int delrow[] = {-1, 0, 1, 0};
//     int delcol[] = {0, 1, 0, -1};

//     for (int j = 0; j < m; j++)
//     {
//         if (not[0][j] == 'O')
//         {
//             vis[0][j] = 1;
//             dfs(0, j, vis, not, delrow, delcol);
//         }
//         if (not[n - 1][j] == 'O')
//         {
//             vis[n - 1][j] = 1;
//             dfs(n - 1, j, vis, not, delrow, delcol);
//         }
//     }
//     for (int i = 0; i < n; i++)
//     {
//         if (not[i][0] == 'O')
//         {
//             vis[i][0] = 1;
//             dfs(i, 0, vis, not, delrow, delcol);
//         }
//         if (not[i][m - 1] == 'O')
//         {
//             vis[i][m - 1] = 1;
//             dfs(i, m - 1, vis, not, delrow, delcol);
//         }
//     }

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             if (!vis[i][j])
//             {
//                 not[i][j] = 'X';
//             }
//         }
//     }

//     return not;
// }
