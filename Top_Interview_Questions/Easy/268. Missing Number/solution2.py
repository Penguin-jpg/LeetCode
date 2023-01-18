from typing import List


class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        exists = [False] * (len(nums) + 1)
        for num in nums:
            exists[num] = True
        for i in range(len(exists)):
            if not exists[i]:
                return i
        return 0
