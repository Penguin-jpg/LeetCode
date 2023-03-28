from typing import List


class Solution:
    def fourSumCount(self, nums1: List[int], nums2: List[int], nums3: List[int], nums4: List[int]) -> int:
        temp, results = [], []
        nums = [nums1, nums2, nums3, nums4]
        self.backtracking(nums, 0, temp, results)
        return len(results)

    def backtracking(self, nums: List[List[int]], index: int, temp: List[int], results: List[int]) -> int:
        if index >= 4:
            result = 0
            for i in range(4):
                result += nums[i][temp[i]]
            if result == 0:
                results.append(1)
            return
        for i in range(0, len(nums[index])):
            temp.append(i)
            self.backtracking(nums, index + 1, temp, results)
            temp.pop()
