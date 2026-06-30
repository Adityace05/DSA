#include <bits/stdc++.h> // striver graphs lect 35
using namespace std;

class Solution
{
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
    {

        // Min-heap for Dijkstra
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Adjacency list
        vector<vector<pair<int, int>>> adj(n + 1);
        vector<int> dist(n + 1, 1e9);
        vector<int> parent(n + 1);

        for (int i = 1; i <= n; i++)
            parent[i] = i;

        // Build graph
        for (int i = 0; i < m; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        // Dijkstra's algorithm from node 1
        dist[1] = 0;
        pq.push({0, 1});

        while (!pq.empty())
        {
            auto [dis, node] = pq.top();
            pq.pop();

            if (dis > dist[node])
                continue;

            for (auto [nd, wt] : adj[node])
            {
                if (dis + wt < dist[nd])
                {
                    dist[nd] = dis + wt;
                    parent[nd] = node;
                    pq.push({dist[nd], nd});
                }
            }
        }

        // If node n is unreachable
        if (dist[n] == 1e9)
            return {-1};

        // Reconstruct path
        vector<int> ans;
        int node = n;
        while (parent[node] != node)
        {
            ans.push_back(node);
            node = parent[node];
        }
        ans.push_back(1);
        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Hardcoded graph example
    int n = 5; // number of nodes
    int m = 6; // number of edges
    vector<vector<int>> edges = {
        {1, 2, 2},
        {1, 3, 4},
        {2, 3, 1},
        {2, 4, 7},
        {3, 5, 3},
        {4, 5, 1}};

    Solution sol;
    vector<int> path = sol.shortestPath(n, m, edges);

    if (path.size() == 1 && path[0] == -1)
    {
        cout << -1 << "\n";
    }
    else
    {
        for (int node : path)
        {
            cout << node << " ";
        }
        cout << "\n";
    }

    return 0;
}
