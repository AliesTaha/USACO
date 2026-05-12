class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        
        dic = defaultdict(list)
        
        for n1, n2, w in times:
            dic[n1].append((n2, w))
        
        heap=[]
        heapq.heappush(heap, (0, k))
        visited=set()
        t_final=0
        while heap:
            t, node=heapq.heappop(heap)
            if node in visited:
                continue
            t_final=max(t, t_final)
            visited.add(node)
            for neighbor, t2 in dic[node]:
                total_time=t+t2
                heapq.heappush(heap, (total_time, neighbor))

        if len(visited)!=n:
            return -1
        return t_final