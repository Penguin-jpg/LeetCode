from typing import List


class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        missing_num = 0
        for i in range(len(nums) + 1):
            missing_num ^= i
        for num in nums:
            missing_num ^= num
        return missing_num
