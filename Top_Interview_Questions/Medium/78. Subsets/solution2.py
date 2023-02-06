from typing import List


class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        if len(nums) == 1 and nums[0] == 0:
            return [[], [0]]
        size, temp, counter = 2 ** len(nums), 0, 0
        results = [[]] * size
        for i in range(size):
            temp = i
            counter = 0
            subset = []
            while temp > 0:
                if temp & 1:
                    subset.append(nums[counter])
                temp >>= 1
                counter += 1
            results[i] = subset
        return results
