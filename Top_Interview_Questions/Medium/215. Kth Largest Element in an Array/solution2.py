from typing import List


class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        return self.quick_select(nums, 0, len(nums) - 1, k)

    def partition(self, nums: List[int], left: int, right: int) -> int:
        pivot, pivot_index = nums[right], left
        for i in range(left, right + 1):
            if nums[i] < pivot:
                nums[i], nums[pivot_index] = nums[pivot_index], nums[i]
                pivot_index += 1
        nums[right], nums[pivot_index] = nums[pivot_index], nums[right]
        return pivot_index

    def quick_select(self, nums: List[int], left: int, right: int, k: int) -> int:
        if left == right:
            return nums[left]
        pivot_index = self.partition(nums, left, right)
        if len(nums) - k == pivot_index:
            return nums[pivot_index]
        elif len(nums) - k < pivot_index:
            return self.quick_select(nums, left, pivot_index - 1, k)
        else:
            return self.quick_select(nums, pivot_index + 1, right, k)
