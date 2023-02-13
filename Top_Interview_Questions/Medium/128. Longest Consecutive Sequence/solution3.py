from typing import List


class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        elements, max_length = set(nums), 0
        for element in elements:
            if element - 1 not in elements:
                end = element + 1
                while end in elements:
                    end += 1
                max_length = max(max_length, end - element)
        return max_length
