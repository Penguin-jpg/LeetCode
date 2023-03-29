from typing import List
import sys


class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        m, n = len(nums1), len(nums2)
        if m < n:
            return self.findMedianSortedArrays(nums2, nums1)
        left, right = 0, n * 2
        while left <= right:
            mid2 = int((left + right) / 2)
            mid1 = m + n - mid2
            L1 = -sys.maxsize if mid1 == 0 else nums1[int((mid1 - 1) / 2)]
            L2 = -sys.maxsize if mid2 == 0 else nums2[int((mid2 - 1) / 2)]
            R1 = sys.maxsize if mid1 == m * 2 else nums1[int(mid1 / 2)]
            R2 = sys.maxsize if mid2 == n * 2 else nums2[int(mid2 / 2)]
            if L1 > R2:
                left = mid2 + 1
            elif L2 > R1:
                right = mid2 - 1
            else:
                return (max(L1, L2) + min(R1, R2)) / 2
        return -1.0
