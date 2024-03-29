from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        return 0 if root is None else max(self.maxDepth(root.left) + 1, self.maxDepth(root.right) + 1)
