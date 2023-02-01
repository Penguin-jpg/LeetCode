from typing import List


class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        n = len(matrix)
        original = matrix
        for i in range(n):
            for j in range(n):
                matrix[j][n - i - 1] = original[i][j]
