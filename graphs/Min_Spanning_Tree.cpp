// A tree in which we have N nodes and N-1 edgees and all nodes are cinnected to each other
// A graph which has min weight sum is called MST ( min spanning tree)


// Prism's Algorithm --> MST

// Prism's Algirithm (time complexity --> ElogE)

// class Solution
// { // prism's Algorithm
// public:
//     int minCostConnectPoints(vector<vector<int>> &points)
//     {
//         int n = points.size();
//         priority_queue<
//             pair<int, int>,
//             vector<pair<int, int>>,
//             greater<pair<int, int>>>
//             pq;

//         vector<int> vis(n, 0);
//         pq.push({0, 0});
//         int sum = 0;

//         while (!pq.empty())
//         {
//             int node = pq.top().second;
//             int wt = pq.top().first;
//             pq.pop();
//             if (vis[node])
//                 continue;
//             vis[node] = 1;
//             sum += wt;

//             for (int i = 0; i < n; i++)
//             {
//                 if (!vis[i])
//                 {
//                     int dist = abs(points[node][0] - points[i][0]) +
//                                abs(points[node][1] - points[i][1]);
//                     pq.push({dist, i});
//                 }
//             }
//         }

//         return sum;
//     }
// };


// by Disjoint Set (time complexity --> ElogV)

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
//     int spanningTree(int V, vector<vector<int>> &edges)
//     {

//         // Step 1: Create DSU
//         DisjointSet ds(V);

//         // Step 2: Store edges as {weight, u, v}
//         vector<pair<int, pair<int, int>>> adj;

//         for (auto &it : edges)
//         {
//             int u = it[0];
//             int v = it[1];
//             int wt = it[2];
//             adj.push_back({wt, {u, v}});
//         }

//         // Step 3: Sort edges by weight
//         sort(adj.begin(), adj.end());

//         int mstWt = 0;

//         // Step 4: Apply Kruskal
//         for (auto &it : adj)
//         {
//             int wt = it.first;
//             int u = it.second.first;
//             int v = it.second.second;

//             if (ds.findUPar(u) != ds.findUPar(v))
//             {
//                 mstWt += wt;
//                 ds.unionBySize(u, v);
//             }
//         }

//         return mstWt;
//     }
// };
