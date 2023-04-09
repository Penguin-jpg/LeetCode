from typing import Optional
import sys


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def __init__(self):
        self.max_sum = -sys.maxsize

    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.get_max_sum(root)
        return self.max_sum

    def get_max_sum(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0
        left_max_sum = max(self.get_max_sum(root.left), 0)
        right_max_sum = max(self.get_max_sum(root.right), 0)
        self.max_sum = max(self.max_sum, root.val + left_max_sum + right_max_sum)
        return root.val + max(left_max_sum, right_max_sum)
