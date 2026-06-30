// // Articulation Points in an Undirected Graph :- Nodes which when removed increase the number of connected components in a graph

// // User function Template for C++

// class Solution
// {
//     int timer = 0;

// private:
//     void dfs(int node, int tin[], int low[], vector<int> adj[], vector<int> &vis, vector<int> &mark, int parent)
//     {
//         vis[node] = 1;
//         tin[node] = low[node] = timer;
//         timer++;
//         int child = 0;
//         for (auto it : adj[node])
//         {
//             if (it == parent)
//                 continue;
//             if (!vis[it])
//             {
//                 dfs(it, tin, low, adj, vis, mark, node);
//                 low[node] = min(low[node], low[it]);
//                 if (low[it] >= tin[node] && parent != -1)
//                 {
//                     mark[node] = 1;
//                 }
//                 child++;
//             }
//             else
//             {
//                 low[node] = min(low[node], tin[it]);
//             }
//         }

//         if (child > 1 && parent == -1)
//         {
//             mark[node] = 1;
//         }
//     }

// public:
//     vector<int> articulationPoints(int V, vector<int> adj[])
//     {
//         vector<int> vis(V, 0);
//         int tin[V];
//         int low[V];
//         vector<int> mark(V, 0);

//         for (int i = 0; i < V; i++)
//         {
//             if (!vis[i])
//             {
//                 dfs(i, tin, low, adj, vis, mark, -1);
//             }
//         }

//         vector<int> ans;
//         for (int i = 0; i < V; i++)
//         {
//             if (mark[i] == 1)
//             {
//                 ans.push_back(i);
//             }
//         }
//         if (ans.size() == 0)
//         {
//             return {-1};
//         }
//         return ans;
//     }
// };