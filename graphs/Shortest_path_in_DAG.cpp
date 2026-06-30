#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>

using namespace std;

void topoSort(int node, vector < pair<int, int> adj[], vector<int> &vis, stack<int> &st)
{
    vis[node] = 1;

    for (auto it : adj[node])
    {
        int p = it.first;
        if (!vis[p])
        {
            topoSort(it, adj, vis, st);
        }
    }
    st.push({
        node,
    })
}

vector<int> shortPath(vector < pair<int, int>> adj[], int v)
{
    vector<int> vis(v, 0);
    stack<int> st;

    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            topoSort(i, adj, v, st);
        }
    }

    vector<int> dist(v, 1000000);
    dist[0] = 0; // taking 0 as src node

    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        for (auto it : adj[node])
        {
            int k = it.first;
            int dis = it.second;
            if (dist[node] + dis < dist[k])
            {
                dist[k] = dist[node] + dis;
            }
        }
    }
    return dist;
}

int main()
{
    int v = 7;
    vector < pair<int, int>> adj[v];

    adj[0].push_back({1, 2});
    adj[1].push_back({3, 1});
    adj[2].push_back({3, 3});
    adj[3].push_back({});
    adj[4].push_back({0, 3});
    adj[4].push_back({2, 1});
    adj[5].push_back({4, 1});
    adj[6].push_back({4, 2});
    adj[6].push_back({5, 3});

    vector<int> shortestPath = shortPath(adj, v);

    return 0;
}