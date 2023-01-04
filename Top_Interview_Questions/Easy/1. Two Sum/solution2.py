from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        table = {num: index for index, num in enumerate(nums)}
        for index, num in enumerate(nums):
            rest = target - num
            if rest in table and table[rest] != index:
                return [index, table[rest]]
