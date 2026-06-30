// // User function Template for C++
// class DisjointSet
// {
//     vector<int> rank, parent, size;

// public:
//     DisjointSet(int n)
//     {
//         rank.resize(n + 1, 0);
//         parent.resize(n + 1);
//         size.resize(n + 1, 1);

//         for (int i = 0; i <= n; i++)
//         {
//             parent[i] = i;
//             size[i] = 1;
//         }
//     }

//     int findUPar(int node)
//     {
//         if (node == parent[node])
//             return node;
//         return parent[node] = findUPar(parent[node]); // path compression
//     }

//     // ✅ Union by Rank
//     void unionByRank(int u, int v)
//     {
//         int ulp_u = findUPar(u);
//         int ulp_v = findUPar(v);
//         if (ulp_u == ulp_v)
//             return;

//         if (rank[ulp_u] < rank[ulp_v])
//         {
//             parent[ulp_u] = ulp_v;
//         }
//         else if (rank[ulp_v] < rank[ulp_u])
//         {
//             parent[ulp_v] = ulp_u;
//         }
//         else
//         {
//             parent[ulp_v] = ulp_u;
//             rank[ulp_u]++;
//         }
//     }

//     // ✅ Union by Size
//     void unionBySize(int u, int v)
//     {
//         int ulp_u = findUPar(u);
//         int ulp_v = findUPar(v);
//         if (ulp_u == ulp_v)
//             return;

//         if (size[ulp_u] < size[ulp_v])
//         {
//             parent[ulp_u] = ulp_v;
//             size[ulp_v] += size[ulp_u];
//         }
//         else
//         {
//             parent[ulp_v] = ulp_u;
//             size[ulp_u] += size[ulp_v];
//         }
//     }
// };

// class Solution
// {
// public:
//     vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators)
//     {
//         // vector<vector<int>> islands;
//         vector<int> vis(m * n, 0);
//         DisjointSet ds(m * n);
//         int k = operators.size();

//         vector<int> ans;
//         int count = 0;
//         int delRow[] = {1, 0, -1, 0};
//         int delCol[] = {0, 1, 0, -1};

//         for (int j = 0; j < k; j++)
//         {
//             int r = operators[j][0];
//             int c = operators[j][1];
//             if (vis[r * m + c])
//             {
//                 ans.push_back(count);
//                 continue;
//             }

//             vis[r * m + c] = 1;
//             count++;

//             for (int i = 0; i < 4; i++)
//             {
//                 int nrow = r + delRow[i];
//                 int ncol = c + delCol[i];
//                 if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && ds.findUPar(r * m + c) != ds.findUPar(nrow * m + ncol) && vis[nrow * m + ncol])
//                 {
//                     count--;
//                     ds.unionBySize(r * m + c, nrow * m + ncol);
//                 }
//             }
//             ans.push_back(count);
//         }

//         return ans;
//     }
// };
