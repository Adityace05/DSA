#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>

using namespace std;
// Note :- don't use vis array as we are travelling to a node many times so we will get the min dist

vector<int> shortPath(vector<int> adj[], int v)
{                               // using queue here
    vector<int> dist(v, 10000); // 10000 means big no.
    vector<int> vis(v, 0);
    int src = 0;
    queue<int> q;

    q.push(src);
    dist[0] = 0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto it : adj[node])
        {
            if (dist[node] + 1 < dist[it])
            {
                dist[it] = dist[node] + 1;
                q.push(it);
            }
        }
    }
    return dist;
}

int main()
{
    int v = 9;
    vector<int> adj[v];

    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[1].push_back(3);
    adj[3].push_back(1);

    adj[2].push_back(3);
    adj[3].push_back(3);

    adj[2].push_back(4);
    adj[4].push_back(2);

    vector<int> shortestPath = shortPath(adj, v);

    return 0;
}