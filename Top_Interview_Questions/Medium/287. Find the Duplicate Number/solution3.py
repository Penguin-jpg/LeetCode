from typing import List


class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        left, right, mid = 0, len(nums) - 1, 0
        while left <= right:
            mid = int((left + right) / 2)
            counter = 0
            for num in nums:
                if num <= mid:
                    counter += 1
            if counter > mid:
                right = mid - 1
            else:
                left = mid + 1
        return left
