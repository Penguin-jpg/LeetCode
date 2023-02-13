from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        current_profit, stock = 0, 0
        for i in range(1, len(prices)):
            if prices[stock] >= prices[i]:
                stock = i
            else:
                current_profit += prices[i] - prices[stock]
                stock = i
        return current_profit
