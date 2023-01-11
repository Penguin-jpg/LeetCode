from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        left, right, profit = 0, 1, 0
        while right < len(prices):
            if prices[left] < prices[right]:
                profit = max(profit, prices[right] - prices[left])
            else:
                left = right
            right += 1
        return profit
