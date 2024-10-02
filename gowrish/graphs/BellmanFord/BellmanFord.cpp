#include <bits/stdc++.h>
using namespace std;

vector<int> bellmanford(int n, int src, vector<tuple<int, int, int>> edges)
{
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (auto edge : edges)
        {
            int u, v, w;
            tie(u, v, w) = edge;
            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (auto edge : edges)
    {
        int u, v, w;
        tie(u, v, w) = edge;
        if (dist[u] != INT_MAX && dist[u] + w < dist[v])
        {
            cout << "Graph has a negative edge cycle" << endl;
            break;
        }
    }
    return dist;
}

int main()
{
    int n = 5;
    int src = 0;
    vector<tuple<int, int, int>> edges = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}};

    vector<int> dist = bellmanford(n, src, edges);

    for (int i = 0; i < n; i++)
    {
        cout << "Distance from source " << src << " to node " << i << " is " << dist[i] << endl;
    }

    return 0;
}
