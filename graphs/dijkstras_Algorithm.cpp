#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

// Works for undirected graphs with non-negative weights
vector<int> dijkstraPQ(int v, vector<pair<int, int>> adj[], int src)
{
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>>
        pq;

    vector<int> dist(v, 1e9);

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty())
    {
        int dis = pq.top().first; 
        int node = pq.top().second;
        pq.pop();

        // Skip outdated entries
        if (dis > dist[node])
            continue;

        for (auto it : adj[node])
        {
            int adjNode = it.first;
            int edgeWeight = it.second;

            if (dis + edgeWeight < dist[adjNode])
            {
                dist[adjNode] = dis + edgeWeight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}

vector<int> dijkstraSET(int v, vector<pair<int, int>> adj[], int src){
    set<pair<int,int>> st;
    vector<int> dist(v, 1e9); 

    st.insert({0,src});
    dist[src] = 0;

    while(!st.empty()){
        auto it = *(st.begin());
        int node = it.second;
        int dis = it.first;
        st.erase(it);

        for (auto it : adj[node])
        {
            int adjNode = it.first;
            int edgeWeight = it.second;

            if (dis + edgeWeight < dist[adjNode])
            {   
                if(dist[adjNode] != 1e9){
                    st.erase({dist[adjNode], adjNode});
                }
                dist[adjNode] = dis + edgeWeight;
                st.insert({dist[adjNode], adjNode});
            }
        }
    }
    return dist;

}

    int main()
{
    int v = 6;
    vector<pair<int, int>> adj[v];

    adj[0].push_back({1, 4});
    adj[0].push_back({2, 4});

    adj[1].push_back({0, 4});
    adj[1].push_back({2, 2});

    adj[2].push_back({0, 4});
    adj[2].push_back({1, 2});
    adj[2].push_back({3, 3});
    adj[2].push_back({4, 1});
    adj[2].push_back({5, 6});

    adj[3].push_back({2, 3});
    adj[3].push_back({5, 2});

    adj[4].push_back({2, 1});
    adj[4].push_back({5, 3});

    adj[5].push_back({2, 6});
    adj[5].push_back({3, 2});
    adj[5].push_back({4, 3});

    vector<int> shortestPath = dijkstraPQ(v, adj, 0);
    // vector<int> shortestPath = dijkstraSET(v, adj, 0);

    for (int i = 0; i < v; i++)
    {
        cout << "Distance from 0 to " << i << " = " << shortestPath[i] << endl;
    }

    return 0;
}
