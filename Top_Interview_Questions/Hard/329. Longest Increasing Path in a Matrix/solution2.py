from typing import List


class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        result = 0
        memo = [[-1 for _ in range(len(matrix[0]))] for _ in range(len(matrix))]
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                result = max(result, self.dfs(matrix, i, j, -1, memo))
        return result

    def dfs(self, matrix: List[List[int]], row: int, col: int, last: int, memo: List[List[int]]) -> int:
        if (
            row < 0
            or row >= len(matrix)
            or col < 0
            or col >= len(matrix[0])
            or matrix[row][col] == -1
            or matrix[row][col] <= last
        ):
            return 0
        if memo[row][col] != -1:
            return memo[row][col]
        temp = matrix[row][col]
        matrix[row][col] = -1
        up = 1 + self.dfs(matrix, row - 1, col, temp, memo)
        down = 1 + self.dfs(matrix, row + 1, col, temp, memo)
        left = 1 + self.dfs(matrix, row, col - 1, temp, memo)
        right = 1 + self.dfs(matrix, row, col + 1, temp, memo)
        matrix[row][col] = temp
        memo[row][col] = max(up, down, left, right)
        return memo[row][col]
