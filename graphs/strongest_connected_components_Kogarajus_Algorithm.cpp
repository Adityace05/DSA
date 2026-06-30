// // Position this line where user code will be pasted. // Kosaraju's Algorithm to find Strongly Connected Components in a directed graph
// class Solution
// {
// private:
//     void dfs(vector<vector<int>> &adj, vector<int> &vis, stack<int> &st, int i)
//     {
//         vis[i] = 1;

//         for (auto it : adj[i])
//         {
//             if (!vis[it])
//             {
//                 dfs(adj, vis, st, it);
//             }
//         }

//         st.push(i);
//     }

//     void dfs1(vector<vector<int>> &adj1, vector<int> &vis, int node)
//     {
//         vis[node] = 1;

//         for (auto it : adj1[node])
//         {
//             if (!vis[it])
//             {
//                 dfs1(adj1, vis, it);
//             }
//         }
//     }

// public:
//     int kosaraju(vector<vector<int>> &adj)
//     {
//         stack<int> st;
//         int n = adj.size();
//         vector<int> vis(n, 0);
//         for (int i = 0; i < n; i++)
//         {
//             if (!vis[i])
//             {
//                 dfs(adj, vis, st, i);
//             }
//         }

//         vector<vector<int>> adj1(n);
//         for (int i = 0; i < n; i++)
//         {
//             vis[i] = 0;
//             for (auto it : adj[i])
//             {
//                 adj1[it].push_back(i);
//             }
//         }

//         int scc = 0;
//         while (!st.empty())
//         {
//             int node = st.top();
//             st.pop();
//             if (!vis[node])
//             {
//                 scc++;
//                 dfs1(adj1, vis, node);
//             }
//         }
//         return scc;
//     }
// };