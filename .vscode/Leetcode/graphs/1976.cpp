// class Solution
// {
// public:
//     int countPaths(int n, vector<vector<int>> &roads)
//     {
//         const int MOD = 1e9 + 7;

//         priority_queue<
//             pair<long long, int>,
//             vector<pair<long long, int>>,
//             greater<pair<long long, int>>>
//             pq; // {time, node}

//         vector<vector<pair<int, int>>> adj(n);
//         for (auto &r : roads)
//         {
//             adj[r[0]].push_back({r[1], r[2]});
//             adj[r[1]].push_back({r[0], r[2]});
//         }

//         vector<long long> dist(n, LLONG_MAX);
//         vector<long long> ways(n, 0);

//         dist[0] = 0;
//         ways[0] = 1;
//         pq.push({0, 0});

//         while (!pq.empty())
//         {
//             auto [time, node] = pq.top();
//             pq.pop();

//             if (time > dist[node])
//                 continue;

//             for (auto &it : adj[node])
//             {
//                 int next = it.first;
//                 long long wt = it.second;
//                 long long newTime = time + wt;

//                 if (newTime < dist[next])
//                 {
//                     dist[next] = newTime;
//                     ways[next] = ways[node];
//                     pq.push({newTime, next});
//                 }
//                 else if (newTime == dist[next])
//                 {
//                     ways[next] = (ways[next] + ways[node]) % MOD;
//                 }
//             }
//         }

//         return ways[n - 1] % MOD;
//     }
// };
