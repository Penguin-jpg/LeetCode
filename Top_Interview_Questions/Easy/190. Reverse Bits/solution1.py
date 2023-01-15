# 由於 python 的數字可以很大，所以方法1沒辦法直接用，只能用 cpp solution3 那種方式


class Solution:
    def reverseBits(self, n: int) -> int:
        result = 0
        for i in range(32):
            result = (result << 1) | (n >> i & 1)
        return result
