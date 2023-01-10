from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0
        queue = [root]
        level = 0
        size = len(queue)
        while len(queue) != 0:
            for i in range(size):
                current = queue.pop(0)
                if current.left is not None:
                    queue.append(current.left)
                if current.right is not None:
                    queue.append(current.right)
            level += 1
            size = len(queue)
        return level
