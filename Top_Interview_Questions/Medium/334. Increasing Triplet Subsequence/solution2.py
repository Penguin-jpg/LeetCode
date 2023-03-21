from typing import List
import sys


class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        c1, c2 = sys.maxsize, sys.maxsize
        for num in nums:
            if num <= c1:
                c1 = num
            elif num <= c2:
                c2 = num
            else:
                return True
        return False
