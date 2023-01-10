from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        return self.get_depth(root, 0)

    def get_depth(self, root: Optional[TreeNode], level) -> int:
        if root is None:
            return level
        left_depth = self.get_depth(root.left, level + 1)
        right_depth = self.get_depth(root.right, level + 1)
        return max(left_depth, right_depth)
