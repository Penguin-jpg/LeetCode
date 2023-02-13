from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        current_profit, profit = 0, 0
        for i in range(1, len(prices)):
            profit = prices[i] - prices[i - 1]
            current_profit += profit if profit > 0 else 0
        return current_profit
