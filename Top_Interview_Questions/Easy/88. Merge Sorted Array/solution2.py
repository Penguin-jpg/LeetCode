from typing import List


class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        i = 0
        for j in range(m, m + n):
            nums1[j] = nums2[i]
            i += 1
        nums1.sort()
