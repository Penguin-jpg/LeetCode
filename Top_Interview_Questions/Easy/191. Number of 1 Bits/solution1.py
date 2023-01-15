class Solution:
    def hammingWeight(self, n: int) -> int:
        counter = 0
        for i in range(32):
            if n & 1:
                counter += 1
            n >>= 1
        return counter
