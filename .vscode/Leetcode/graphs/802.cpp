// // find eventual safe states
// // 1) logic:- nodes without envolve in a dicle and nodes which are directed towards a cycled element are all safe nodes
// // concept used :- cycle in a directed graph



// class Solution
// {
// private:
//     bool dfs(int node, vector<vector<int>> &graph, vector<int> &vis, vector<int> &visPath, vector<int> &check)
//     {
//         vis[node] = 1;
//         visPath[node] = 1;
//         check[node] = 0;

//         for (auto it : graph[node])
//         {
//             if (!vis[it])
//             {
//                 if (dfs(it, graph, vis, visPath, check))
//                 {
//                     check[node] = 0;  // no need to use
//                     return true;
//                 }
//             }
//             else if (visPath[it])
//             {
//                 check[node] = 0; // no need to use
//                 return true;
//             }
//         }
//         check[node] = 1;
//         visPath[node] = 0;
//         return false;
//     }

// public:
//     vector<int> eventualSafeNodes(vector<vector<int>> &graph)
//     {
//         int v = graph.size();
//         vector<int> check(v, 0);
//         vector<int> vis(v, 0);
//         vector<int> visPath(v, 0);
//         vector<int> safeNode;

//         for (int i = 0; i < v; i++)
//         {
//             if (!vis[i])
//             {
//                 dfs(i, graph, vis, visPath, check);
//             }
//         }

//         for (int i = 0; i < v; i++)
//         {
//             if (check[i])
//             {
//                 safeNode.push_back(i);
//             }
//         }
//         return safeNode;
//     }
// };