from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        table = {"counter": 0, "result": 0}  # use a dict to wrap counter and result so python can change it
        self.inorder(root, table, k)
        return table["result"]

    def inorder(self, root: Optional[TreeNode], table: dict, k: int):
        if root is None:
            return
        self.inorder(root.left, table, k)
        table["counter"] += 1
        if table["counter"] == k:
            table["result"] = root.val
            return
        self.inorder(root.right, table, k)
