from typing import List
from collections import deque


class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        dq = deque()
        results = []
        for right in range(len(nums)):
            if len(dq) > 0 and dq[0] == right - k:
                dq.popleft()
            while len(dq) > 0 and nums[dq[-1]] < nums[right]:
                dq.pop()
            dq.append(right)
            if right + 1 - k >= 0:
                results.append(nums[dq[0]])
        return results
