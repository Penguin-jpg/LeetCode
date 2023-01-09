from typing import Optional, List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        results = []
        self.inorder(root, results)
        return results

    def inorder(self, root: Optional[TreeNode], results: List[int]):
        if root is None:
            return root
        self.inorder(root.left, results)
        results.append(root.val)
        self.inorder(root.right, results)
