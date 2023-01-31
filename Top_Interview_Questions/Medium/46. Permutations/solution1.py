from typing import List


class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        results = []
        self.find_permutations(nums, 0, results)
        return results

    def find_permutations(self, nums: List[int], index: int, results: List[List[int]]):
        if index >= len(nums):
            results.append(nums[:])  # need to use slice operator or it will get the wrong reference
            return
        for i in range(index, len(nums)):
            nums[i], nums[index] = nums[index], nums[i]
            self.find_permutations(nums, index + 1, results)
            nums[i], nums[index] = nums[index], nums[i]
