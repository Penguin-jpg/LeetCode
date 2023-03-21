from typing import List
import sys


class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        k = 3
        candidates = [sys.maxsize] * (k - 1)
        for num in nums:
            for i in range(len(candidates)):
                if num <= candidates[i]:
                    candidates[i] = num
                    break
                elif i == k - 2:
                    return True
        return False
