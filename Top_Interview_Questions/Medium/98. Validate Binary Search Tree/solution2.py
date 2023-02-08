from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        return self.is_valid(root, None, None)

    def is_valid(
        self, root: Optional[TreeNode], min_node: Optional[TreeNode], max_node: Optional[TreeNode]
    ) -> bool:
        if root is None:
            return True
        if (min_node is not None and root.val <= min_node.val) or (
            max_node is not None and root.val >= max_node.val
        ):
            return False
        return self.is_valid(root.left, min_node, root) and self.is_valid(root.right, root, max_node)
