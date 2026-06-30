// 1)Each node of graph we have to color ,we have to use 2 colors for all the graph to color
// 2) adjecent node shouldn't have same color
// 3) Every graph without cycle is always bipatite graph
// 4) Any graph with even no of node in cycle (even cycle length) is a bipatite graph
// time complexity :- O(v + 2v)
// space complexity:- O(v)

#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

bool checkDfs(int node, int col, vector<int> adj[], vector<int> &color)
{
    color[node] = col;

    for (auto it : adj[node])
    {
        if (color[it] == -1)
        {
            if (!checkDfs(it, !col, adj, color))
            {
                return false;
            }
            else if (color[it] == col)
            {
                return false;
            }
        }
    }
    return true;
}
bool isBipatiteDfs(int v, vector<int> adj[])
{
    vector<int> color(v, -1);

    for (int i = 0; i < v; i++)
    {
        if (color[i] == -1)
        {
            if (!checkDfs(i, 0, adj, color))
            {
                return false;
            }
        }
    }
    return true;
}

bool checkBfs(int start, vector<int> adj[], vector<int> &color)
{
    queue<int> q;
    q.push(start);
    color[start] = 0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto it : adj[node])
        {
            if (color[it] == -1)
            {
                color[it] = !color[node];
                q.push(it);
            }
            else if (color[it] == color[node])
            {
                return false;
            }
        }
    }
    return true;
}

bool isBipatiteBfs(int v, vector<int> adj[])
{
    vector<int> color(v, -1);

    for (int i = 0; i < v; i++)
    {
        if (color[i] == -1)
        {
            if (!checkBfs(i, adj, color))
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    int v = 6;
    vector<int> adj[v];

    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[1].push_back(3);
    adj[3].push_back(1);

    adj[2].push_back(4);
    adj[4].push_back(2);

    adj[3].push_back(4);
    adj[4].push_back(3);

    adj[4].push_back(5);
    adj[5].push_back(4);

    cout << isBipatiteDfs(v, adj);
    cout << isBipatiteBfs(v, adj);

    return 0;
}