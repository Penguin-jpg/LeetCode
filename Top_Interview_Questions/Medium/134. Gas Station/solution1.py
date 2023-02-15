from typing import List


class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        j, k, current_gas = 0, 0, 0
        for i in range(1, len(gas)):
            if gas[i] >= cost[i]:
                current_gas = gas[i]
                j, k = (i + 1) % len(gas), i
                while j != i:
                    current_gas -= cost[k]
                    if current_gas < 0:
                        break
                    current_gas += gas[j]
                    j = (j + 1) % len(gas)
                    k = (k + 1) % len(gas)
                if current_gas >= cost[k]:
                    return i
        return -1
