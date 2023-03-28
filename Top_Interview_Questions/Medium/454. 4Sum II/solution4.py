from typing import List


class Solution:
    def fourSumCount(self, nums1: List[int], nums2: List[int], nums3: List[int], nums4: List[int]) -> int:
        table = {}
        counter = 0
        for num3 in nums3:
            for num4 in nums4:
                sum = num3 + num4
                if not sum in table:
                    table[sum] = 0
                table[sum] += 1
        for num1 in nums1:
            for num2 in nums2:
                target = 0 - num1 - num2
                if target in table:
                    counter += table[target]
        return counter
