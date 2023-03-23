from typing import List
from collections import Counter


class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        counter = Counter(nums)
        temp = sorted(counter.items(), key=lambda x: x[1], reverse=True)
        return [temp[i][0] for i in range(k)]


# 也可以直接用 python 的 Counter 來解
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        counter = Counter(nums)
        top_k = counter.most_common(k)
        return [pair[0] for pair in top_k]
