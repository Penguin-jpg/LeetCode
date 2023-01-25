from typing import List


class Solution:
    def maxArea(self, height: List[int]) -> int:
        left, right, max_value = 0, len(height) - 1, 0
        while left < right:
            max_value = max(max_value, min(height[left], height[right]) * (right - left))
            if height[left] < height[right]:
                left += 1
            else:
                right -= 1
        return max_value
