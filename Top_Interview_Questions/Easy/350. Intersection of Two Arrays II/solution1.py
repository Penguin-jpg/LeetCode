from typing import List


class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        table = {}
        result = []
        for num in nums1:
            if num not in table:
                table[num] = 0
            table[num] += 1
        for num in nums2:
            if num in table and table[num] > 0:
                table[num] -= 1
                result.append(num)
        return result
