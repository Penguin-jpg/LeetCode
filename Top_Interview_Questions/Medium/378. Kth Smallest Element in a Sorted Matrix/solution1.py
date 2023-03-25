from typing import List


class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        result = [num for row in matrix for num in row]
        result.sort()
        return result[k - 1]
