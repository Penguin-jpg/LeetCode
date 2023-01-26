from typing import List


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        sum, results = 0, []
        nums.sort()
        for i in range(0, len(nums) - 2):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            left, right = i + 1, len(nums) - 1
            while left < right:
                sum = nums[i] + nums[left] + nums[right]
                if sum < 0:
                    left += 1
                elif sum > 0:
                    right -= 1
                else:
                    triplet = [nums[i], nums[left], nums[right]]
                    results.append(triplet)
                    while left < right and nums[left] == triplet[1]:
                        left += 1
                    while right > left and nums[right] == triplet[2]:
                        right -= 1
        return results
