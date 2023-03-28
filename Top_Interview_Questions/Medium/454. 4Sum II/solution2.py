from typing import List


class Solution:
    def fourSumCount(self, nums1: List[int], nums2: List[int], nums3: List[int], nums4: List[int]) -> int:
        counter = 0
        for num1 in nums1:
            for num2 in nums2:
                for num3 in nums3:
                    for num4 in nums4:
                        if num1 + num2 + num3 + num4 == 0:
                            counter += 1
        return counter
