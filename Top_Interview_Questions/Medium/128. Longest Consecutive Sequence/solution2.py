from typing import List


class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        table = {num: 0 for num in nums}
        max_length, current_length = 0, 0
        for num in nums:
            if table[num] != 0:
                continue
            elif num - 1 not in table and num + 1 not in table:
                current_length = 1
                table[num] = current_length
            elif num - 1 not in table:
                current_length = table[num + 1] + 1
                table[num] = current_length
                table[num + table[num + 1]] = current_length
            elif num + 1 not in table:
                current_length = table[num - 1] + 1
                table[num] = current_length
                table[num - table[num - 1]] = current_length
            else:
                current_length = table[num - 1] + table[num + 1] + 1
                table[num] = current_length
                table[num - table[num - 1]] = current_length
                table[num + table[num + 1]] = current_length
            max_length = max(max_length, current_length)
        return max_length
