class Solution:
    def isHappy(self, n: int) -> bool:
        slow = self.get_digit_square_sum(n)
        fast = self.get_digit_square_sum(self.get_digit_square_sum(n))
        while slow != fast:
            slow = self.get_digit_square_sum(slow)
            fast = self.get_digit_square_sum(self.get_digit_square_sum(fast))
        return fast == 1

    def get_digit_square_sum(self, n: int) -> bool:
        return sum([int(digit) ** 2 for digit in str(n)])
