def dfs(node,adj,visited):
    visited[node]=True
    for i in adj[node]:
        if not visited[i]:
            dfs(i,adj,visited)
            
def main():
    n,m=map(int,input().split())
    adj=[[] for i in range(n)]
    for i in range(m):
        u,v=map(int,input().split())
        adj[u].append(v)
        adj[v].append(u)
    visited=[False]*n
    for i in range(n):
        if not visited[i]:
            dfs(i,adj,visited)
    print(visited)