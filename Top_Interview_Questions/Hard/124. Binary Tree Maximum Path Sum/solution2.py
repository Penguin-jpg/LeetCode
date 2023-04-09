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
        self.gain_from_subtree(root)
        return self.max_sum

    def gain_from_subtree(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0
        gain_from_left_subtree = max(self.gain_from_subtree(root.left), 0)
        gain_from_right_subtree = max(self.gain_from_subtree(root.right), 0)
        self.max_sum = max(self.max_sum, root.val + gain_from_left_subtree + gain_from_right_subtree)
        return root.val + max(gain_from_left_subtree, gain_from_right_subtree)
