from typing import List


class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        carry = 1
        for index in range(len(digits) - 1, -1, -1):
            digits[index] += carry
            carry = digits[index] // 10
            digits[index] %= 10
        if carry == 1:
            digits.insert(0, 1)
        return digits
