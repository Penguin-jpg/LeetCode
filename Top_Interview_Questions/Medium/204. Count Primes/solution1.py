class Solution:
    def countPrimes(self, n: int) -> int:
        counter = 0
        for i in range(0, n):
            if self.is_prime(i):
                counter += 1
        return counter

    def is_prime(self, n: int) -> bool:
        if n == 0 or n == 1:
            return False
        i = 2
        while i <= n // i:
            if n % i == 0:
                return False
            i += 1
        return True
