from typing import List


class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        unique_elements = {num for num in nums}
        return (sum(nums) - 2 * sum(unique_elements)) * -1
