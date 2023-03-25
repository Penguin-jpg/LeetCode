from typing import List
from heapq import heappush, heappop


class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        min_heap = []
        for row in matrix:
            for num in row:
                heappush(min_heap, num)
        for _ in range(k - 1):
            heappop(min_heap)
        return heappop(min_heap)
