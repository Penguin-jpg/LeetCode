class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        maxNum = 1162261467  # 3^19
        return n > 0 and maxNum % n == 0
