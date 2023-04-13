from typing import List


class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        result = 0
        for i in range(len(points)):
            slopes = {}
            current_max = 0
            for j in range(i + 1, len(points)):
                dy, dx = points[j][1] - points[i][1], points[j][0] - points[i][0]
                gcd = self.GCD(dy, dx)
                slope = f"{dy//gcd}_{dx//gcd}"
                if slope in slopes:
                    slopes[slope] += 1
                else:
                    slopes[slope] = 1
            for frequency in slopes.values():
                current_max = max(current_max, frequency)
            current_max += 1
            result = max(result, current_max)
        return result

    def GCD(self, a, b) -> int:
        if b == 0:
            return a
        return self.GCD(b, a % b)
