from typing import List


class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        m, n = len(nums1), len(nums2)
        merged = [0] * (n + m)
        i, j, k, mid = 0, 0, 0, int((m + n) / 2)
        while i < m and j < n:
            if nums1[i] < nums2[j]:
                merged[k] = nums1[i]
                i += 1
            else:
                merged[k] = nums2[j]
                j += 1
            k += 1
        while i < m:
            merged[k] = nums1[i]
            i += 1
            k += 1
        while j < n:
            merged[k] = nums2[j]
            j += 1
            k += 1
        return merged[mid] if len(merged) % 2 != 0 else (merged[mid - 1] + merged[mid]) / 2
