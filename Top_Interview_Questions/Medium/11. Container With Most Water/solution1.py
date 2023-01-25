from typing import List


class Solution:
    def maxArea(self, height: List[int]) -> int:
        max_value = 0
        for i in range(1, len(height) - 1):
            for j in range(i + 1, len(height)):
                max_value = max(max_value, min(height[i], height[j]) * (j - i))
        return max_value
