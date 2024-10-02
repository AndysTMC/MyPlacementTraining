#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int src, dest, weight;
};

bool compareEdges(Edge e1, Edge e2)
{
    return e1.weight < e2.weight;
}

int find(int parent[], int i)
{
    if (parent[i] != i)
        parent[i] = find(parent, parent[i]);
    return parent[i];
}

void unionSets(int parent[], int rank[], int x, int y)
{
    int rootX = find(parent, x);
    int rootY = find(parent, y);
    if (rank[rootX] < rank[rootY])
        parent[rootX] = rootY;
    else if (rank[rootX] > rank[rootY])
        parent[rootY] = rootX;
    else
    {
        parent[rootY] = rootX;
        rank[rootX]++;
    }
}

vector<Edge> kruskalMST(int V, vector<Edge> &edges)
{
    vector<Edge> result;
    sort(edges.begin(), edges.end(), compareEdges);
    int parent[V], rank[V];
    for (int v = 0; v < V; ++v)
    {
        parent[v] = v;
        rank[v] = 0;
    }
    int e = 0;
    while (result.size() < V - 1 && e < edges.size())
    {
        Edge next_edge = edges[e++];
        int x = find(parent, next_edge.src);
        int y = find(parent, next_edge.dest);
        if (x != y)
        {
            result.push_back(next_edge);
            unionSets(parent, rank, x, y);
        }
    }
    return result;
}

int main()
{
    int V = 4; // Number of vertices
    vector<Edge> edges = {
        {0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}};

    vector<Edge> mst = kruskalMST(V, edges);

    cout << "Edges in the Minimum Spanning Tree:" << endl;
    for (auto &edge : mst)
    {
        cout << edge.src << " -- " << edge.dest << " == " << edge.weight << endl;
    }

    return 0;
}
