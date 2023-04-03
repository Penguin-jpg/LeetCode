from typing import List


class Solution:
    def trap(self, height: List[int]) -> int:
        result, left, right = 0, 0, len(height) - 1
        max_left, max_right = height[0], height[-1]
        while left <= right:
            if max_left < max_right:
                if height[left] > max_left:
                    max_left = height[left]
                else:
                    result += max_left - height[left]
                left += 1
            else:
                if height[right] > max_right:
                    max_right = height[right]
                else:
                    result += max_right - height[right]
                right -= 1
        return result
