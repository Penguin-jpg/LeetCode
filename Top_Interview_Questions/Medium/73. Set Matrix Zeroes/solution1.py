from typing import List


class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        is_zero_row, is_zero_col = False, False
        for i in range(len(matrix[0])):
            if matrix[0][i] == 0:
                is_zero_row = True
                break
        for i in range(len(matrix)):
            if matrix[i][0] == 0:
                is_zero_col = True
                break
        for i in range(1, len(matrix)):
            for j in range(1, len(matrix[0])):
                if matrix[i][j] == 0:
                    matrix[i][0] = 0
                    matrix[0][j] = 0
        for i in range(1, len(matrix)):
            for j in range(1, len(matrix[0])):
                if matrix[i][0] == 0 or matrix[0][j] == 0:
                    matrix[i][j] = 0
        if is_zero_row:
            for i in range(len(matrix[0])):
                matrix[0][i] = 0
        if is_zero_col:
            for i in range(len(matrix)):
                matrix[i][0] = 0
