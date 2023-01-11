from typing import List
import sys


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        min_buy = sys.maxsize
        profit = 0
        for i in range(len(prices)):
            if prices[i] < min_buy:
                min_buy = prices[i]
            current_profit = prices[i] - min_buy
            if current_profit > profit:
                profit = current_profit
        return profit
