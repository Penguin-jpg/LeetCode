from typing import List


class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        directions = ((0, 1), (1, 0), (0, -1), (-1, 0))
        m, n = len(matrix), len(matrix[0])
        results = [0 for _ in range(m * n)]
        steps = [n, m - 1]
        direction_index, row, col, index = 0, 0, -1, 0
        while steps[direction_index % 2] > 0:
            for _ in range(steps[direction_index % 2]):
                row += directions[direction_index][0]
                col += directions[direction_index][1]
                results[index] = matrix[row][col]
                index += 1
            steps[direction_index % 2] -= 1
            direction_index = (direction_index + 1) % 4
        return results
