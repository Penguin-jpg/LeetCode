from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        table = {}
        for index, num in enumerate(nums):
            rest = target - num
            if rest in table:
                return [index, table[rest]]
            else:
                table[num] = index
