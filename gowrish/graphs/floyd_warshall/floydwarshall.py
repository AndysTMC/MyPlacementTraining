INF = float('inf')

def floyd_warshall(graph):
    n = len(graph)
    dist = [[INF]* n for _ in range(n)]
    
    for i in range(n):
        for j in range(n):
            dist[i][j] = graph[i][j]
    
    for k in range(n):
        for i in range(n):
            for j in range(n):
                dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j])
    return dist

graph = [
    [0, 3, INF, INF],
    [2, 0, INF, INF],
    [INF, 7, 0, 1],
    [6, INF, INF, 0]
]

distances = floyd_warshall(graph)

print("Shortest distances between every pair of vertices:")
for row in distances:
    print(row)