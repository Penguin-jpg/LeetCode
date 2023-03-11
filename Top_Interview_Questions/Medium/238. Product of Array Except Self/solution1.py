from typing import List


class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        zero_pos, product = [], 1
        for i, num in enumerate(nums):
            if num == 0:
                zero_pos.append(i)
                if len(zero_pos) > 1:
                    return [0] * len(nums)
            else:
                product *= num
        results = [0] * len(nums)
        if len(zero_pos) == 1:
            results[zero_pos[0]] = product
            return results
        for i, num in enumerate(nums):
            results[i] = product // num
        return results
