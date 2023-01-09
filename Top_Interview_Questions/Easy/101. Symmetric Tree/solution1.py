from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        return self.check_symmetric(root.left, root.right)

    def check_symmetric(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        if root1 is None and root2 is None:
            return True
        elif root1 is None or root2 is None:
            return False
        elif root1.val != root2.val:
            return False
        return self.check_symmetric(root1.left, root2.right) and self.check_symmetric(root1.right, root2.left)
