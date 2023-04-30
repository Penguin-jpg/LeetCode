from typing import List


class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        result = 0
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                result = max(result, self.dfs(matrix, i, j, -1))
        return result

    def dfs(self, matrix: List[List[int]], row: int, col: int, last: int) -> int:
        if (
            row < 0
            or row >= len(matrix)
            or col < 0
            or col >= len(matrix[0])
            or matrix[row][col] == -1
            or matrix[row][col] <= last
        ):
            return 0
        temp = matrix[row][col]
        matrix[row][col] = -1
        up = 1 + self.dfs(matrix, row - 1, col, temp)
        down = 1 + self.dfs(matrix, row + 1, col, temp)
        left = 1 + self.dfs(matrix, row, col - 1, temp)
        right = 1 + self.dfs(matrix, row, col + 1, temp)
        matrix[row][col] = temp
        return max(up, down, left, right)
