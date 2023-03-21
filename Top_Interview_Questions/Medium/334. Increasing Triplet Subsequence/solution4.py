from typing import List
import sys
import bisect


class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        k = 3
        candidates = [sys.maxsize] * (k - 1)
        for num in nums:
            index = bisect.bisect_left(candidates, num)
            if index >= k - 1:
                return True
            candidates[index] = num
        return False
