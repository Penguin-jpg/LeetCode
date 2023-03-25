from typing import List
from heapq import heappush, heappop

# 由於 python 沒有辦法做 max-heap，所以我們要手動將數字加上負號來模擬 max-heap


class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        max_heap = []
        for row in matrix:
            for num in row:
                heappush(max_heap, -num)
                if len(max_heap) > k:
                    heappop(max_heap)
        return -heappop(max_heap)
