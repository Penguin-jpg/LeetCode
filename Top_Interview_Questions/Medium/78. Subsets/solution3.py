from typing import List


class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        if len(nums) == 1 and nums[0] == 0:
            return [[], [0]]
        size = 1 << len(nums)
        results = [[]] * size
        for i in range(size):
            temp, subset = i, []
            for j in range(len(nums)):
                if temp & 1:
                    subset.append(nums[j])
                temp >>= 1
            results[i] = subset
        return results
