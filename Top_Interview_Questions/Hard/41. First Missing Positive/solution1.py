from typing import List


class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        i, n = 0, len(nums)
        while i < n:
            num = nums[i]
            if num > 0 and num <= n and num != nums[num - 1]:
                nums[i], nums[num - 1] = nums[num - 1], num
            else:
                i += 1
        for i, num in enumerate(nums):
            if i + 1 != num:
                return i + 1
        return n + 1
