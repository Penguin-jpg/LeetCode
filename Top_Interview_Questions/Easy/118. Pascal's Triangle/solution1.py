from typing import List


class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        if numRows == 1:
            return [[1]]
        results = [[1]]
        for i in range(1, numRows):
            row = [1]
            for j in range(1, len(results[i - 1])):
                row.append(results[i - 1][j - 1] + results[i - 1][j])
            row.append(1)
            results.append(row)
        return results
