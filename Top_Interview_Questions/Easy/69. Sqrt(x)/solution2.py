# 疊代
class Solution:
    def mySqrt(self, x: int) -> int:
        r = x
        while r * r > x:
            r = (r + x // r) // 2
        return r


# 遞迴
class Solution:
    def mySqrt(self, x: int) -> int:
        r = x
        return self.helper(x, r)

    def helper(self, x: int, r: int) -> int:
        if r * r > x:
            return self.helper(x, (r + x // r) // 2)
        return r
