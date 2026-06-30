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
//     int makeConnected(int n, vector<vector<int>> &connections)
//     {
//         DisjointSet ds(n);
//         int count = 0;
//         int k = 0;

//         for (auto it : connections)
//         {
//             int u = it[0];
//             int v = it[1];
//             if (ds.findUPar(u) != ds.findUPar(v))
//             {
//                 ds.unionBySize(u, v);
//             }
//             else
//             {
//                 count++;
//             }
//         }

//         for (int i = 0; i < n; i++)
//         {
//             if (ds.findUPar(i) == i)
//             {
//                 k++;
//             }
//         }

//         if (count >= k - 1)
//         {
//             return k - 1;
//         }
//         return -1;
//     }
// };