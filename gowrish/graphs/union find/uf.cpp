#include <bits/stdc++.h>
using namespace std;

class uf
{
public:
    vector<int> parent;
    vector<int> size;
    int n;
    uf(int n)
    {
        this->n = n;
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int find(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }
    void unite(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return;
        if (size[x] < size[y])
            swap(x, y);
        parent[y] = x;
        size[x] += size[y];
    }
};