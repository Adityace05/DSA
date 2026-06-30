// #include <bits/stdc++.h>
// using namespace std;

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
//         return parent[node] = findUPar(parent[node]);
//     }

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

//     int getSize(int node)
//     {
//         return size[findUPar(node)];
//     }
// };

// class Solution
// {
// public:
//     int largestIsland(vector<vector<int>> &grid)
//     {
//         int n = grid.size();
//         DisjointSet ds(n * n);

//         int delRow[] = {1, 0, -1, 0};
//         int delCol[] = {0, 1, 0, -1};

//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 if (grid[i][j] == 0)
//                     continue;

//                 int node = i * n + j;
//                 for (int k = 0; k < 4; k++)
//                 {
//                     int nrow = i + delRow[k];
//                     int ncol = j + delCol[k];

//                     if (nrow >= 0 && nrow < n &&
//                         ncol >= 0 && ncol < n &&
//                         grid[nrow][ncol] == 1)
//                     {

//                         int adjNode = nrow * n + ncol;
//                         ds.unionBySize(node, adjNode);
//                     }
//                 }
//             }
//         }

//         int maxcnt = 0;

//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 if (grid[i][j] == 1)
//                     continue;

//                 unordered_set<int> st;
//                 int cnt = 1;

//                 for (int k = 0; k < 4; k++)
//                 {
//                     int nrow = i + delRow[k];
//                     int ncol = j + delCol[k];

//                     if (nrow >= 0 && nrow < n &&
//                         ncol >= 0 && ncol < n &&
//                         grid[nrow][ncol] == 1)
//                     {

//                         int parent = ds.findUPar(nrow * n + ncol);
//                         if (st.insert(parent).second) // insert :- {iterator , bool} :- bool = true if insertion happened
//                         {
//                             cnt += ds.getSize(parent);
//                         }
//                     }
//                 }

//                 maxcnt = max(maxcnt, cnt);
//             }
//         }

//         for (int i = 0; i < n * n; i++)
//         {
//             maxcnt = max(maxcnt, ds.getSize(i));
//         }

//         return maxcnt;
//     }
// };
