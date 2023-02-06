from typing import List


class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        results, subset = [[]], []
        self.backtracking(nums, 0, subset, results)
        return results

    def backtracking(self, nums: List[int], index: int, subset: List[int], results: List[List[int]]):
        if index >= len(nums):
            return
        for i in range(index, len(nums)):
            subset.append(nums[i])
            results.append(subset[:])  # need to pass a new reference
            self.backtracking(nums, i + 1, subset, results)
            subset.pop()
