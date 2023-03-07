from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        nodes, current = [], root
        while len(nodes) != 0 or current is not None:
            if current is not None:
                nodes.append(current)
                current = current.left
            else:
                node = nodes.pop()
                k -= 1
                if k == 0:
                    return node.val
                current = node.right
        return -1
