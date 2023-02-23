class Solution:
    def trailingZeroes(self, n: int) -> int:
        counter, i = 0, 5
        while i <= n:
            counter += n // i
            i *= 5
        return counter
