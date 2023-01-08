from typing import List


class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        results, i, j = [], 0, 0
        while i < m and j < n:
            if nums1[i] < nums2[j]:
                results.append(nums1[i])
                i += 1
            else:
                results.append(nums2[j])
                j += 1
        while j < n:
            results.append(nums2[j])
            j += 1
        for index, num in enumerate(results):
            nums1[index] = num
