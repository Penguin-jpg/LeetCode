class Solution:
    def trailingZeroes(self, n: int) -> int:
        counter, temp = 0, 0
        for i in range(5, n + 1, 5):
            temp = i
            while temp != 0 and temp % 5 == 0:
                counter += 1
                temp //= 5
        return counter
