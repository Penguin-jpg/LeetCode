from typing import List


class ValWithIndex:
    def __init__(self, val, index):
        self.val = val
        self.index = index


class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        vals = [ValWithIndex(num, i) for i, num in enumerate(nums)]
        counters = [0] * len(nums)
        self.merge_sort(vals, 0, len(nums) - 1, counters)
        return counters

    def merge_sort(self, vals: List[ValWithIndex], left: int, right: int, counters: List[int]):
        if left < right:
            mid = (left + right) // 2
            self.merge_sort(vals, left, mid, counters)
            self.merge_sort(vals, mid + 1, right, counters)
            self.merge(vals, left, mid, right, counters)

    def merge(self, vals: List[ValWithIndex], left: int, mid: int, right: int, counters: List[int]):
        merged = [ValWithIndex(0, 0)] * (right - left + 1)
        merged_index = 0
        current_num_elements_in_right_array_smaller_than_left_array = 0
        i, j = left, mid + 1
        while i <= mid and j <= right:
            if vals[i].val > vals[j].val:
                current_num_elements_in_right_array_smaller_than_left_array += 1
                merged[merged_index] = vals[j]
                j += 1
            else:
                counters[vals[i].index] += current_num_elements_in_right_array_smaller_than_left_array
                merged[merged_index] = vals[i]
                i += 1
            merged_index += 1

        while i <= mid:
            counters[vals[i].index] += current_num_elements_in_right_array_smaller_than_left_array
            merged[merged_index] = vals[i]
            i += 1
            merged_index += 1

        while j <= right:
            merged[merged_index] = vals[j]
            j += 1
            merged_index += 1

        start = left
        for m in merged:
            vals[start] = m
            start += 1
