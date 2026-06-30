// Linear ordering of vertices as such that if therre is an edge between u and v , u appears before v in that ordering
// Only valid in DAG( directed acyclic graph)

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
using namespace std;

// class Solution    Kahn's Algorithm
// { leetcode 210  time complexity:- O(v + e)
// public:
//     vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
//     {

//         vector<vector<int>> adj(numCourses);
//         vector<int> indegree(numCourses, 0);
//         queue<int> q;
//         vector<int> topo;

//         // Build graph
//         for (auto &p : prerequisites)
//         {
//             int course = p[0];
//             int prereq = p[1];
//             adj[prereq].push_back(course);
//             indegree[course]++;
//         }

//         // Push nodes with indegree 0
//         for (int i = 0; i < numCourses; i++)
//         {
//             if (indegree[i] == 0)
//             {
//                 q.push(i);
//             }
//         }

//         // Kahn's BFS
//         while (!q.empty())
//         {
//             int node = q.front();
//             q.pop();
//             topo.push_back(node);

//             for (int next : adj[node])
//             {
//                 indegree[next]--;
//                 if (indegree[next] == 0)
//                 {
//                     q.push(next);
//                 }
//             }
//         }

//         // Cycle check
//         if (topo.size() != numCourses)
//             return {};

//         return topo;
//     }
// };

void dfs(int node, vector<int> &vis, stack<int> &st, vector<int> adj[])
{
    vis[node] = 1;

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, vis, st, adj);
        }
    }

    st.push(node);
}

vector<int> topoSort(int v, vector<int> adj[])
{
    vector<int> vis(v, 0);
    stack<int> st;

    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, st, adj);
        }
    }
    vector<int> ans;

    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

int main()
{
    int v = 6;
    vector<int> adj[v];

    adj[5].push_back(0);
    adj[5].push_back(2);
    adj[4].push_back(0);
    adj[2].push_back(3);
    adj[3].push_back(1);
    adj[4].push_back(1);

    vector<int> he = topoSort(v, adj);

    for (int i = 0; i < v; i++)
    {
        cout << he[i] << " ";
    }

    return 0;
}