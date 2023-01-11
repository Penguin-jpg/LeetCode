from typing import List


class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        rows = [[1] * (i + 1) for i in range(numRows)]
        for i in range(numRows):
            for j in range(1, i):
                rows[i][j] = rows[i - 1][j - 1] + rows[i - 1][j]
        return rows
