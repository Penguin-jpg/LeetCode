from typing import List


class Solution:
    def trap(self, height: List[int]) -> int:
        result, n = 0, len(height)
        max_left, max_right = [0] * n, [0] * n
        for i in range(1, n):
            max_left[i] = max(height[i - 1], max_left[i - 1])
        for i in range(n - 2, -1, -1):
            max_right[i] = max(height[i + 1], max_right[i + 1])
        for i in range(n):
            level = min(max_left[i], max_right[i])
            result += level - height[i] if level >= height[i] else 0
        return result
