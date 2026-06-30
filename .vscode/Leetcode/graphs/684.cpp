// class Solution
// {
// private:
//     vector<int> parent, rank;

//     int find(int x)
//     {
//         if (parent[x] != x)
//             parent[x] = find(parent[x]);
//         return parent[x];
//     }

//     bool unite(int u, int v)
//     {
//         int pu = find(u);
//         int pv = find(v);

//         if (pu == pv)
//             return false; // cycle detected

//         if (rank[pu] < rank[pv])
//             parent[pu] = pv;
//         else if (rank[pv] < rank[pu])
//             parent[pv] = pu;
//         else
//         {
//             parent[pv] = pu;
//             rank[pu]++;
//         }
//         return true;
//     }

// public:
//     vector<int> findRedundantConnection(vector<vector<int>> &edges)
//     {
//         int n = edges.size();

//         parent.resize(n + 1);
//         rank.resize(n + 1, 0);

//         for (int i = 1; i <= n; i++)
//             parent[i] = i;

//         for (auto &e : edges)
//         {
//             if (!unite(e[0], e[1]))
//             {
//                 return e; // THIS is the redundant edge
//             }
//         }

//         return {};
//     }
// };
