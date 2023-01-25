class Solution:
    def reverse(self, x: int) -> int:
        result, max_range, min_range = 0, 2**31 - 1, -(2**31)
        while x != 0:
            result = result * 10 + x % 10
            x //= 10
        return 0 if result < min_range or result > max_range else result
