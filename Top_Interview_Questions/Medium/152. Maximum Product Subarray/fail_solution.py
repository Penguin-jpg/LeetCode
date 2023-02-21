from typing import List
import sys


class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        product, max_product = 1, -sys.maxsize
        negative_pos = []
        for i, num in enumerate(nums):
            if num < 0:
                negative_pos.append(i)
            product *= num
        if len(negative_pos) % 2 == 0:
            return product
        num_negtaive = len(negative_pos)
        start = -1
        for i in range(num_negtaive):
            if i + num_negtaive - 1 > num_negtaive:
                break
            product = 1
            end = negative_pos[i + num_negtaive - 1] if i + num_negtaive - 1 < num_negtaive else len(nums)
            for j in range(start + 1, end):
                product *= nums[j]
            max_product = max(max_product, product)
            start = negative_pos[i]
        return max_product
