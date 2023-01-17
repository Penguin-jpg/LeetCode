from typing import List


class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        table = {}
        for num in nums:
            if num in table:
                table[num] += 1
            else:
                table[num] = 1
            if table[num] > 1:
                return True
        return False
