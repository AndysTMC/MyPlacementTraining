class Edge:
    def __init__(self, src, dest, weight):
        self.src = src
        self.dest = dest
        self.weight = weight

def find(parent, i):
    if parent[i] != i:
        parent[i] = find(parent, parent[i])
    return parent[i]

def union(parent, rank, x, y):
    rootX = find(parent, x)
    rootY = find(parent, y)
    if rank[rootX] < rank[rootY]:
        parent[rootX] = rootY
    elif rank[rootX] > rank[rootY]:
        parent[rootY] = rootX
    else:
        parent[rootY] = rootX
        rank[rootX] += 1

def kruskal(V, edges):
    result = []
    edges.sort(key=lambda e: e.weight)
    parent = list(range(V))
    rank = [0] * V
    e = 0
    while len(result) < V - 1:
        edge = edges[e]
        e += 1
        x = find(parent, edge.src)
        y = find(parent, edge.dest)
        if x != y:
            result.append(edge)
            union(parent, rank, x, y)
    return result
