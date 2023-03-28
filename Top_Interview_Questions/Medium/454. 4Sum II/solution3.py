from typing import List
from collections import Counter


class Solution:
    def fourSumCount(self, nums1: List[int], nums2: List[int], nums3: List[int], nums4: List[int]) -> int:
        table = Counter(nums4)
        counter = 0
        for num1 in nums1:
            for num2 in nums2:
                for num3 in nums3:
                    target = 0 - num1 - num2 - num3
                    if target in table:
                        counter += table[target]
        return counter
