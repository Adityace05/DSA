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