from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        max_current, max_so_far = 0, 0
        for i in range(1, len(prices)):
            max_current += prices[i] - prices[i - 1]
            max_current = max(0, max_current)
            max_so_far = max(max_so_far, max_current)
        return max_so_far
