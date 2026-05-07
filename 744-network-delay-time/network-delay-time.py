class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        adjacency_list=[[] for _ in range(n+1)]
        for u, v, w in times:
            adjacency_list[u].append((v,w))
        print(adjacency_list)

        INF = float('inf')
        dist = [INF for _ in range(n+1)]
        dist[k]=0
        min_heap= [(0, k)]
        visited=set()

        while min_heap:
            curr_d, node=heapq.heappop(min_heap)
            if node in visited:
                continue
            neighbors=adjacency_list[node]
            visited.add(node)
            for v,w in neighbors:
                new_dist= curr_d+w
                if new_dist < dist[v]:
                    dist[v]=new_dist
                final_d=dist[v]
                heapq.heappush(min_heap, (final_d, v))
        
        if INF in dist[1:]:
            return -1

        return max(dist[1:])