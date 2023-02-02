from typing import List


class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        row, col, m, n, index = 0, 0, len(matrix), len(matrix[0]), 1
        last_up_row, last_down_row, last_left_col, last_right_col = 0, m, -1, n
        results = [matrix[0][0]] * (m * n)
        while index < m * n:
            while col + 1 < last_right_col and index < m * n:
                col += 1
                results[index] = matrix[row][col]
                index += 1
            last_right_col = col
            while row + 1 < last_down_row and index < m * n:
                row += 1
                results[index] = matrix[row][col]
                index += 1
            last_down_row = row
            while col - 1 > last_left_col and index < m * n:
                col -= 1
                results[index] = matrix[row][col]
                index += 1
            last_left_col = col
            while row - 1 > last_up_row and index < m * n:
                row -= 1
                results[index] = matrix[row][col]
                index += 1
            last_up_row = row
        return results
