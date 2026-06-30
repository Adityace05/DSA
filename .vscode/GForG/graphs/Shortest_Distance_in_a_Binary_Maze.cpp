// // User function Template for C++

// class Solution
// {
// public:
//     int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
//                      pair<int, int> destination)
//     {
//         // code here
//         queue<pair<int, pair<int, int>>> q;
//         int n = grid.size();
//         int m = grid[0].size();
//         vector<vector<int>> dist(n, vector<int>(m, 1e9));

//         if (source.first == destination.first && source.second == destination.second)
//             return 0;

//         dist[source.first][source.second] = 0;
//         q.push({0, {source.first, source.second}});

//         int delRow[] = {-1, 0, 1, 0};
//         int delCol[] = {0, 1, 0, -1};
//         while (!q.empty())
//         {
//             auto it = q.front();
//             q.pop();
//             int dis = it.first;
//             int row = it.second.first;
//             int col = it.second.second;

//             for (int i = 0; i < 4; i++)
//             {
//                 int nrow = row + delRow[i];
//                 int ncol = col + delCol[i];

//                 if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && dis + 1 < dist[nrow][ncol])
//                 {
//                     if (nrow == destination.first && ncol == destination.second)
//                     {
//                         return dis + 1;
//                     }

//                     q.push({(dis + 1), {nrow, ncol}});
//                     dist[nrow][ncol] = dis + 1;
//                 }
//             }
//         }
//         return -1;
//     }
// };
