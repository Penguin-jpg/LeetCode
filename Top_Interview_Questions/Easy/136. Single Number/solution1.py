from typing import List


class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        table = {}
        for num in nums:
            if num not in table:
                table[num] = 1
            else:
                table[num] += 1
        for num, counter in table.items():
            if counter == 1:
                return num
