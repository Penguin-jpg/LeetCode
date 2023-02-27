from typing import List


class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        m, n, counter = len(grid), len(grid[0]), 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == "1":
                    self.dfs(grid, i, j, m, n)
                    counter += 1
        return counter

    def dfs(self, grid: List[List[int]], row: int, col: int, m: int, n: int):
        if row < 0 or row >= m or col < 0 or col >= n or grid[row][col] != "1":
            return
        grid[row][col] = "x"
        self.dfs(grid, row + 1, col, m, n)
        self.dfs(grid, row - 1, col, m, n)
        self.dfs(grid, row, col + 1, m, n)
        self.dfs(grid, row, col - 1, m, n)
