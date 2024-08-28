import heapq
def dijkstras(graph, start):
            distance = {node: 0.0 for node in graph}
            distance[start] = 1.0
            pq = [(-1.0, start)]
            while pq:
                cd, cn = heapq.heappop(pq)
                cd = -cd
                if cd < distance[cn]:
                    continue
                for neighbor, weight in graph[cn].items():
                    dist = weight * cd
                    if dist > distance[neighbor]:
                        distance[neighbor] = dist
                        heapq.heappush(pq, (-dist, neighbor))
            return distance