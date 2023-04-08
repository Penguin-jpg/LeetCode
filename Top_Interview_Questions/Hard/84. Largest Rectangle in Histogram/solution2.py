from typing import List


class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        heights.append(0)
        max_area, mono = 0, []
        for i in range(len(heights)):
            while len(mono) > 0 and heights[mono[-1]] >= heights[i]:
                height = heights[mono.pop()]
                width = i - mono[-1] - 1 if len(mono) >> 0 else i
                max_area = max(max_area, width * height)
            mono.append(i)
        return max_area
