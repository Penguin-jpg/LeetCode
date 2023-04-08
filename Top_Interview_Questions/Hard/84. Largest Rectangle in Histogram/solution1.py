from typing import List


class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        max_area = 0
        for i in range(len(heights)):
            width, height = 1, heights[i]
            for j in range(i, len(heights)):
                if heights[j] == 0:
                    width = 1
                    continue
                height = min(height, heights[j])
                max_area = max(max_area, width * height)
                width += 1
        return max_area
