class Solution:
    def mySqrt(self, x: int) -> int:
        start, end, mid, result = 0, x, 0, 0
        while start <= end:
            mid = (start + end) // 2
            if mid * mid == x:
                return mid
            elif mid * mid < x:
                start = mid + 1
                result = mid
            else:
                end = mid - 1
        return result
