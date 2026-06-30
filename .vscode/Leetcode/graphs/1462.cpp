// class Solution
// { method 1 :- Floyd-Warshall Algorithm
// public:
//     vector<bool> checkIfPrerequisite(int numCourses,
//                                      vector<vector<int>> &prerequisites,
//                                      vector<vector<int>> &queries)
//     {

//         vector<vector<bool>> reach(numCourses, vector<bool>(numCourses, false));

//         for (auto &p : prerequisites)
//         {
//             reach[p[0]][p[1]] = true;
//         }

//         for (int k = 0; k < numCourses; k++)
//         {
//             for (int i = 0; i < numCourses; i++)
//             {
//                 if (reach[i][k])
//                 {
//                     for (int j = 0; j < numCourses; j++)
//                     {
//                         if (reach[k][j])
//                         {
//                             reach[i][j] = true;
//                         }
//                     }
//                 }
//             }
//         }

//         vector<bool> ans;
//         for (auto &q : queries)
//         {
//             ans.push_back(reach[q[0]][q[1]]);
//         }

//         return ans;
//     }
// };

// Method 2: DFS + Memoization
// class Solution
// {
// private:
//     vector<vector<int>> dp; // memo table

//     bool isPar(int node, vector<vector<int>> &par, int neb,
//                vector<int> &vis)
//     {

//         if (node == neb)
//             return true;
//         if (dp[node][neb] != -1)
//             return dp[node][neb];
//         if (vis[node])
//             return false;

//         vis[node] = 1;

//         for (auto p : par[node])
//         {
//             if (isPar(p, par, neb, vis))
//             {
//                 return dp[node][neb] = 1;
//             }
//         }
//         return dp[node][neb] = 0;
//     }

// public:
//     vector<bool> checkIfPrerequisite(int numCourses,
//                                      vector<vector<int>> &prerequisites,
//                                      vector<vector<int>> &queries)
//     {

//         vector<vector<int>> par(numCourses);
//         dp.assign(numCourses, vector<int>(numCourses, -1));

//         vector<bool> ans(queries.size(), false);

//         for (auto &it : prerequisites)
//         {
//             par[it[1]].push_back(it[0]);
//         }

//         for (int i = 0; i < queries.size(); i++)
//         {
//             int u = queries[i][0];
//             int v = queries[i][1];
//             vector<int> vis(numCourses, 0);
//             ans[i] = isPar(v, par, u, vis);
//         }
//         return ans;
//     }
// };
