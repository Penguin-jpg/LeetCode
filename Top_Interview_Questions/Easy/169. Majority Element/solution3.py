from typing import List


class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        half = len(nums) // 2
        table = {}
        for num in nums:
            if num in table:
                table[num] += 1
            else:
                table[num] = 1
            if table[num] > half:
                return num
        return nums[0]
