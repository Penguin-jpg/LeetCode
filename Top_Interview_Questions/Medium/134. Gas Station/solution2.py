from typing import List


class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        total_sum, sub_sum, start = 0, 0, 0
        for i in range(len(gas)):
            total_sum += gas[i] - cost[i]
            if total_sum < sub_sum:
                sub_sum = total_sum
                start = i + 1
        return -1 if total_sum < 0 else start % len(gas)
