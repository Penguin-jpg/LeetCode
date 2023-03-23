from typing import List
from collections import Counter
from heapq import heappush, heappop


class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        counter = Counter(nums)
        min_heap = []
        for num, frequency in counter.items():
            heappush(min_heap, (frequency, num))
            if len(min_heap) > k:
                heappop(min_heap)
        results = []
        for _ in range(k):
            _, num = heappop(min_heap)
            results.append(num)
        return results
