class Solution:
    def reverse(self, x: int) -> int:
        result, negative, max_range, min_range = 0, x < 0, 2**31 - 1, -(2**31)
        temp = list(str(abs(x)))  # need to convert to list since python str is immutable
        i, j = 0, len(temp) - 1
        while i < j:
            temp[i], temp[j] = temp[j], temp[i]
            i += 1
            j -= 1
        for digit in temp:
            result = result * 10 + int(digit)
        result = -result if negative else result
        return 0 if result < min_range or result > max_range else result
