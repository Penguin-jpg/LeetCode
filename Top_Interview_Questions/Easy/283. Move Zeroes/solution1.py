from typing import List


class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        pos = -1
        for i in range(len(nums)):
            if pos == -1 and nums[i] == 0:
                pos = i
            elif pos != -1 and nums[i] != 0:
                nums[pos], nums[i] = nums[i], nums[pos]
                pos += 1
