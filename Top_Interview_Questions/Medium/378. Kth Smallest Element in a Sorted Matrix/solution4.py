from typing import List


class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        n = len(matrix)
        left, right = matrix[0][0], matrix[n - 1][n - 1]
        result = 0
        while left <= right:
            mid = int((left + right) / 2)
            if self.count_less_or_equal(matrix, mid, n) >= k:
                right = mid - 1
                result = mid
            else:
                left = mid + 1
        return result

    def count_less_or_equal(self, matrix: List[List[int]], num: int, n: int) -> int:
        col, counter = n - 1, 0
        for row in matrix:
            while col >= 0 and row[col] > num:
                col -= 1
            counter += col + 1
        return counter
