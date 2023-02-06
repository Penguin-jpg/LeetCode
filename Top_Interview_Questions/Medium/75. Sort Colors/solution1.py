from typing import List


class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        self.quick_sort(nums, 0, len(nums) - 1)

    def partition(self, nums: List[int], left: int, right: int) -> int:
        pivot = nums[right]
        pivot_pos = left
        for i in range(left, right):
            if nums[i] < pivot:
                nums[i], nums[pivot_pos] = nums[pivot_pos], nums[i]
                pivot_pos += 1
        nums[right], nums[pivot_pos] = nums[pivot_pos], nums[right]
        return pivot_pos

    def quick_sort(self, nums: List[int], left: int, right: int) -> None:
        if left < right:
            pivot = self.partition(nums, left, right)
            self.quick_sort(nums, left, pivot - 1)
            self.quick_sort(nums, pivot + 1, right)
