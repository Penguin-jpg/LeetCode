class Solution:
    def reverse(self, x: int) -> int:
        result, negative, max_range, min_range = 0, x < 0, 2**31 - 1, -(2**31)
        x = abs(x)
        while x > 0:
            result = result * 10 + x % 10
            if result > max_range or result < min_range:
                return 0
            x //= 10
        return -result if negative else result
