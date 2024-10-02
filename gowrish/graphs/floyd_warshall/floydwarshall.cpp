#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> floydwarshall(vector<vector<int>> graph)
{
    int n = graph.size();
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dist[i][j] = graph[i][j];
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    return dist;
}

int main()
{
    vector<vector<int>> graph = {
        {0, 3, INT_MAX, INT_MAX},
        {2, 0, INT_MAX, INT_MAX},
        {INT_MAX, 7, 0, 1},
        {6, INT_MAX, INT_MAX, 0}};

    vector<vector<int>> distances = floydwarshall(graph);

    cout << "Shortest distances between every pair of vertices:" << endl;
    for (const auto &row : distances)
    {
        for (int val : row)
        {
            if (val == INT_MAX)
                cout << "INF ";
            else
                cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
