from typing import List


class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        duplicate, pos, counter = -101, 0, 0
        for index, num in enumerate(nums):
            if num != duplicate:
                counter += 1
                duplicate = nums[index]
                nums[pos] = nums[index]
                pos += 1
        return counter
