#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int n, vector<pair<int, int>> adj[], int src)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty())
    {
        int node = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[node])
            continue;

        for (auto &edge : adj[node])
        {
            int next = edge.first;
            int weight = edge.second;
            if (dist[node] + weight < dist[next])
            {
                dist[next] = dist[node] + weight;
                pq.push({dist[next], next});
            }
        }
    }
    return dist;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    int src;
    cin >> src;
    vector<int> dist = dijkstra(n, adj, src);
    for (int d : dist)
        cout << d << " ";
    return 0;
}
