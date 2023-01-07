# 參考解答: 先將 digits map 成 str 並轉成 int 做加法，再轉成 str 取字元變 list

from typing import List


class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        return [int(digit) for digit in str(int("".join(map(str, digits))) + 1)]
