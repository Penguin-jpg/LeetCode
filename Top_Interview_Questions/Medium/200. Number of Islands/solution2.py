from typing import List
from collections import deque


class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        m, n, counter = len(grid), len(grid[0]), 0
        directions = ((0, 1), (0, -1), (1, 0), (-1, 0))
        points = deque([])
        row, col = 0, 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == "1":
                    counter += 1
                    points.append((i, j))
                    while len(points) != 0:
                        current = points.popleft()
                        for x, y in directions:
                            row = current[0] + x
                            col = current[1] + y
                            if row < 0 or row >= m or col < 0 or col >= n or grid[row][col] != "1":
                                continue
                            grid[row][col] = "x"
                            points.append((row, col))
        return counter
