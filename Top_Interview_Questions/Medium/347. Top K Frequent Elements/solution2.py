from typing import List
from collections import Counter


class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        counter = Counter(nums)
        buckets = [[] for _ in range(len(nums) + 1)]
        for num, frequency in counter.items():
            buckets[frequency].append(num)
        results = []
        for i in range(len(buckets) - 1, -1, -1):
            for num in buckets[i]:
                results.append(num)
                if len(results) == k:
                    return results
        return results
