#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <string>
using namespace std;

// leetcode 269
// Alien dictionary is given we have to return topo sort; i.e output :-   [b, d, a, c]

string alienDictionary(int k, int v, vector<string> &alien)
{
    vector<int> adj[v];
    for (int i = 0; i < v - 1; i++)
    {
        string s1 = alien[i];
        string s2 = alien[i + 1];
        int len = min(s1.size(), s2.size()); // like baa, abcd then len = 3
        for (int ptr = 0; ptr < len; ptr++)
        {
            if (s1[ptr] != s2[ptr])
            {                                                // b != a  also b before a
                adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a'); // 'b' --> 'a'
                break;                                       // as it is an dictionary no need to check further
            }
        }
    }

    // now topo sort algo

    vector<int> indegree(v, 0);
    queue<int> q;
    vector<int> topo;

    for (int i = 0; i < v; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }

    // pushing the nodes which have 0 indegree
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }
    string ans;
    for (int i = 0; i < k; i++)
    {
        ans.push_back(topo[i]);
    }

    return ans;
}

int main()
{
    vector<string> alien = {"baa", "abcd", "abca", "cab", "cad"};
    int v = alien.size();
    int k = 4;
    string ans = alienDictionary(k, v, alien);

    for (int i = 0; i < k; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}