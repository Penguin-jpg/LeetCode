from typing import List


class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        original = nums[:]
        for i in range(len(nums)):
            nums[(i + k) % len(nums)] = original[i]
