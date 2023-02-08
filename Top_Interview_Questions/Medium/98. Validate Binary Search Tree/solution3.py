from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        self.previous = None  # use self to simulate global variable
        return self.is_valid(root)

    def is_valid(self, root: Optional[TreeNode]) -> bool:
        if root is None:
            return True
        if not self.is_valid(root.left):
            return False
        if self.previous is not None and self.previous.val >= root.val:
            return False
        self.previous = root
        return self.is_valid(root.right)
