def bellman_ford(n, edges, src):
    dist = [float('inf')] * n
    dist[src] = 0

    for _ in range(n - 1):
        for u, v, w in edges:
            if dist[u] != float('inf') and dist[u] + w < dist[v]:
                dist[v] = dist[u] + w

    for u, v, w in edges:
        if dist[u] != float('inf') and dist[u] + w < dist[v]:
            print("Graph contains negative weight cycle")
            return None

    return dist

def main():
    n, m = map(int, input().split())
    edges = []
    for _ in range(m):
        u, v, w = map(int, input().split())
        edges.append((u, v, w))
    src = int(input())
    dist = bellman_ford(n, edges, src)
    if dist:
        print(dist)

if __name__ == "__main__":
    main()
