#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Graph
{
    int v;
    list<int> *l;

public:
    Graph(int v)
    {
        this->v = v;
        l = new list<int>[v];
    }

    void addEdge(int u, int v)
    {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void printAdjList()
    {
        for (int i = 0; i < v; i++)
        {
            cout << i << " : ";
            for (auto n : l[i])
            {
                cout << n << ' ';
            }
            cout << endl;
        }
    }

    void BFS()
    {
        queue<int> Q;
        vector<bool> vis(v, false);

        Q.push(0);
        vis[0] = true;

        while (!Q.empty())
        {
            int u = Q.front();
            Q.pop();

            cout << u << ' ';

            for (int v : l[u])
            {
                if (!vis[v])
                {
                    vis[v] = true;
                    Q.push(v);
                }
            }
        }
        cout << endl;
    }

    void dfsHelper(int u, vector<bool> &vis)
    {
        cout << u << ' ';
        vis[u] = true;

        for (auto v : l[u])
        {
            if (!vis[v])
            {
                dfsHelper(v, vis);
            }
        }
    }

    void DFS()
    {
        vector<bool> vis(v, false);

        for (int i = 0; i < v; i++)
        { // loop is for diconnected graph
            if (!vis[i])
            {
                dfsHelper(i, vis);
            }
        }

        cout << endl;
    }

    bool isCycleUndirDFS(int src, int par, vector<bool> &vis)
    {
        vis[src] = true;
        for (auto v : l[src])
        {
            if (!vis[v])
            {
                if (isCycleUndirDFS(v, src, vis))
                    return true;
            }
            else if (v != par)
            {
                return true;
            }
        }
        return false;
    }

    bool cycleDfs()
    {

        vector<bool> vis(v, false);

        for (int i = 0; i < v; i++)
        { // loop is for diconnected graph
            if (!vis[i])
            {
                if (isCycleUndirDFS(i, -1, vis))
                {
                    return true;
                }
            }
        }

        return false;
    }

    bool isCycleUndirBFS(int src, vector<bool> &vis)
    {
        queue<pair<int, int>> Q;
        vector<bool> vis(v, false);

        Q.push({src, -1});
        vis[0] = true;

        while (!Q.empty())
        {
            int u = Q.front().first;
            int par = Q.front().second;
            Q.pop();

            list<int> neighbors = l[u];

            for (int v : neighbors)
            {
                if (!vis[v])
                {
                    Q.push({v, u});
                    vis[v] = true;
                }
                else if (v != par)
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool cycleBfs()
    {

        vector<bool> vis(v, false);

        for (int i = 0; i < v; i++)
        { // loop is for diconnected graph
            if (!vis[i])
            {
                if (isCycleUndirBFS(i, vis))
                {
                    return true;
                }
            }
        }

        return false;
    }
};

int main()
{
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    g.printAdjList();

    cout << "BFS: ";
    g.BFS();

    cout << "DFS: ";
    g.DFS();
    cout << g.cycleDfs() << endl;
    cout << g.cycleBfs() << endl;

    return 0;
}
