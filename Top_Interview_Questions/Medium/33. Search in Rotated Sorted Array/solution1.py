from typing import List
import math


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        pivot, left, right, comparator = nums[0], 0, len(nums) - 1, 0
        while left <= right:
            mid = (left + right) // 2
            if ((target < pivot) and (nums[mid] < pivot)) or ((target >= pivot) and (nums[mid] >= pivot)):
                comparator = nums[mid]
            else:
                if target < pivot:
                    comparator = -math.inf
                else:
                    comparator = math.inf
            if target == comparator:
                return mid
            elif target > comparator:
                left = mid + 1
            else:
                right = mid - 1
        return -1
