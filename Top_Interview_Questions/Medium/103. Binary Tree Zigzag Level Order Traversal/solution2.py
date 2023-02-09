from typing import Optional, List
from collections import deque


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if root is None:
            return []
        results, nodes = [], deque([root])
        size, from_left, current = len(nodes), True, None
        while len(nodes) != 0:
            values = [0] * size
            for i in range(size):
                current = nodes.popleft()
                index = i if from_left else size - i - 1
                values[index] = current.val
                if current.left is not None:
                    nodes.append(current.left)
                if current.right is not None:
                    nodes.append(current.right)
            size = len(nodes)
            results.append(values)
            from_left = not from_left
        return results
