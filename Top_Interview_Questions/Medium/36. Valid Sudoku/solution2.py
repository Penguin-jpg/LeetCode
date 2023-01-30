from typing import List
from collections import defaultdict


class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        row_nums = defaultdict(set)
        col_nums = defaultdict(set)
        grid_nums = defaultdict(set)
        for i in range(9):
            for j in range(9):
                if board[i][j] != ".":
                    num = int(board[i][j])
                    grid_row, grid_col = i // 3, j // 3
                    if num in row_nums[i] or num in col_nums[j] or num in grid_nums[(grid_row, grid_col)]:
                        return False
                    row_nums[i].add(num)
                    col_nums[j].add(num)
                    grid_nums[(grid_row, grid_col)].add(num)
        return True
