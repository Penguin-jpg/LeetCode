from typing import List


class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        counter, winner = 0, 0
        for num in nums:
            if counter == 0:
                winner = num
                counter += 1
            elif num != winner:
                counter -= 1
            else:
                counter += 1
        return winner
