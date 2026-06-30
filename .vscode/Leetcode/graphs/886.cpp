// class Solution
// {
// private:
//     bool dfs(int node, int col, vector<vector<int>> &adj, vector<int> &color)
//     {

//         color[node] = col;

//         for (auto it : adj[node])
//         {
//             if (color[it] == -1)
//             {
//                 if (!dfs(it, !col, adj, color))
//                 {
//                     return false;
//                 }
//             }
//             else if (color[it] == col)
//             {
//                 return false;
//             }
//         }
//         return true;
//     }

// public:
//     bool possibleBipartition(int n, vector<vector<int>> &dislikes)
//     {
//         vector<vector<int>> adj(n);
//         vector<int> color(n, -1);

//         for (auto &it : dislikes)
//         {
//             adj[it[0] - 1].push_back(it[1] - 1);
//             adj[it[1] - 1].push_back(it[0] - 1);
//         }

//         for (int i = 0; i < n; i++)
//         {
//             if (color[i] == -1)
//             {
//                 if (!dfs(i, 0, adj, color))
//                 {
//                     return false;
//                 }
//             }
//         }

//         return true;
//     }
// };