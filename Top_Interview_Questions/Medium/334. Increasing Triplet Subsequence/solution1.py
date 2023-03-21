from typing import List


class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        for i in range(len(nums) - 2):
            for j in range(i + 1, len(nums) - 1):
                for k in range(j + 1, len(nums)):
                    if nums[i] < nums[j] and nums[j] < nums[k]:
                        return True
        return False
